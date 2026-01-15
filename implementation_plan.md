# Push Swap 4 Implementation Plan: Full LIS

## Goal
Implement a robust **Longest Increasing Subsequence (LIS)** algorithm to optimize the sorting process. Instead of arbitrarily keeping 3 nodes in Stack A, we will keep the entire LIS of the input array in Stack A, pushing only the non-LIS elements to Stack B. This reduces the number of operations required to sort the stack.

## Algorithm Overview

1.  **LIS Calculation**:
    -   Since N <= 500, an **O(N²)** dynamic programming approach is acceptable and simpler to implement in C than O(N log N).
    -   We need to handle the cyclic nature of the stack. For simplicity, we can solve LIS for the linear representation and try all N rotations? No, too slow (500*500^2).
    -   Better approach: Fix the start at the minimum element index? Or just find the LIS of the linear list `[min_index...end, 0...min_index-1]`?
    -   Actually, for `push_swap`, the "Sequence" must be ordered by index.
    -   We will calculate LIS based on the current linear arrangement of Stack A.
    -   We will store `lis_flag` in each node.

2.  **Push Strategy**:
    -   Iterate through Stack A.
    -   If `node->lis_flag == false`, push to B ([pb](file:///Users/macbookpro2019/42-home/push_swap_2/src/ops_push.c#36-42)).
    -   Else, rotate ([ra](file:///Users/macbookpro2019/42-home/push_swap_3/src/ops_rotate.c#31-37)) to keeping it in A.
    -   Wait, we should rotate such that we access the non-LIS nodes efficiently.

3.  **Greedy Sort (Existing)**:
    -   Once non-LIS nodes are in B, use the existing "Cheapest Insertion" logic to move them back to A.
    -   This part remains largely unchanged from `push_swap_3`.

## Detailed Steps

### 1. Update Data Structure ([t_node](file:///Users/macbookpro2019/42-home/push_swap_3/src/init_b.c#110-119))
Add a boolean flag `is_lis` to [t_node](file:///Users/macbookpro2019/42-home/push_swap_3/src/init_b.c#110-119) in [push_swap.h](file:///Users/macbookpro2019/42-home/push_swap/includes/push_swap.h).

### 2. Implement `lis.c`
Create `src/lis.c` with the following logic:
-   `calculate_lis(t_node *stack)`:
    -   Convert linked list to array `int *arr` for easier indexing (temporarily).
    -   Use O(N²) DP: `len[i]` = length of LIS ending at `i`.
    -   Backtrack to find the actual elements and mark `node->is_lis = true`.
    -   *Optimization*: Since the stack is circular, the LIS might wrap around.
        -   However, simpler strategy: Find the node with index `0` (or minimum value) and treat it as the "virtual start" of the sorted sequence. The LIS must be a subsequence of the sorted order.
        -   Actually, simpler: Just find LIS of the current array.
        -   But wait, relative order matters. `3 4 5 1 2`. LIS is `3 4 5` (len 3) or `1 2` (len 2). If we keep `3 4 5`, we push `1 2`.
        -   Ideally we want the longest subsequence that is *sorted*.
        -   So we should check LIS starting from *each* index? No, O(N^3).
        -   Standard approach: Find LIS of the array. The circular shift [min_on_top](file:///Users/macbookpro2019/42-home/push_swap_3/src/sort.c#68-80) handles the offset.
        -   Wait, if `1 2` is kept, we have `3 4 5` in B. We push back.
        -   If `3 4 5` is kept, we have `1 2` in B.
        -   We want to keep the Maximum number of elements.
        -   So maximizing LIS length is key.

### 3. Modify [sort_stacks](file:///Users/macbookpro2019/42-home/push_swap_3/src/sort.c#81-106) ([sort.c](file:///Users/macbookpro2019/42-home/push_swap/src/sort.c))
-   Call `calculate_lis(*a)`.
-   Loop through A:
    -   If `!a->is_lis`, [pb](file:///Users/macbookpro2019/42-home/push_swap_2/src/ops_push.c#36-42).
    -   Else [ra](file:///Users/macbookpro2019/42-home/push_swap_3/src/ops_rotate.c#31-37).
    -   (Be careful to track `size` of A so we don't infinite loop).

### 4. Verification
-   Ensure [pb](file:///Users/macbookpro2019/42-home/push_swap_2/src/ops_push.c#36-42) doesn't break LIS property of remaining A.
-   Ensure Greedy Insert works with the kept LIS.

## Files to Modify
-   [includes/push_swap.h](file:///Users/macbookpro2019/42-home/push_swap/includes/push_swap.h): Add `is_lis` to [t_node](file:///Users/macbookpro2019/42-home/push_swap_3/src/init_b.c#110-119).
-   `src/lis.c`: New file.
-   [src/sort.c](file:///Users/macbookpro2019/42-home/push_swap/src/sort.c): Modify [sort_stacks](file:///Users/macbookpro2019/42-home/push_swap_3/src/sort.c#81-106).
-   [Makefile](file:///Users/macbookpro2019/42-home/push_swap/Makefile): Add `lis.c`.

## User Review Required
No major breaking changes. The core algorithm logic is additive.
