/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro2019 <macbookpro2019@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:00:00 by macbookpro2       #+#    #+#             */
/*   Updated: 2026/01/15 00:03:23 by macbookpro2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_node **a) {
  t_node *biggest_node;

  biggest_node = find_max(*a);
  if (*a == biggest_node)
    ra(a, true);
  else if ((*a)->next == biggest_node)
    rra(a, true);
  if ((*a)->value > (*a)->next->value)
    sa(a, true);
}

// NOTE: My Plan mentions LIS. A true LIS is complex O(N log N).
// A common optimization for push_swap is to just keep the "LIS" in A, and push
// others to B. However, standard "Turk Algo" simply moves EVERYTHING to B
// (except 3), then moves back greedily. This is effectively "LIS = 3 nodes"
// which is often good enough for 100/500 random. For stricter LIS compliance
// request: I will implement a simplified LIS or simply push all to B (as it's
// often more efficient than maintaining a complex LIS in C). Given "100" or
// "500" constraints, fully moving to B is the standard competitive strategy.
// BUT, if the user explicitly wants LIS, I should respect that.
// Detailed LIS logic in C with linked list is heavy.
// Let's implement the standard "push all but 3" strategy first as it guarantees
// Sorting. "LIS" can be interpreted as "Longest Sorted Subsequence kept in A".
// Correct implementation:
// 1. Push all nodes to B except 3 (can optimize to leave generic sorted
// subsequence).
// 2. Sort 3.
// 3. Greedy insert back (Algorithm described in Plan step 4).
// Let's stick to "Push all to B until 3 left" as it is robust.

static void move_b_to_a(t_node **a, t_node **b) {
  t_node *cheapest_node;

  cheapest_node = get_cheapest(*b);
  if (cheapest_node->above_median && cheapest_node->target_node->above_median) {
    while (*b != cheapest_node && *a != cheapest_node->target_node)
      rr(a, b, true);
    current_index(*a);
    current_index(*b);
  } else if (!(cheapest_node->above_median) &&
             !(cheapest_node->target_node->above_median)) {
    while (*b != cheapest_node && *a != cheapest_node->target_node)
      rrr(a, b, true);
    current_index(*a);
    current_index(*b);
  }
  prep_for_push(b, cheapest_node, 'b');
  prep_for_push(a, cheapest_node->target_node, 'a');
  pa(a, b, true);
}

static void min_on_top(t_node **a) {
  t_node *min_node;

  min_node = find_min(*a);
  while ((*a)->value != min_node->value) // Comparing values or pointers
  {
    if (min_node->above_median)
      ra(a, true);
    else
      rra(a, true);
  }
}

void sort_stacks(t_node **a, t_node **b) {
  int len_a;
  int push_count;
  int i;

  len_a = stack_len(*a);
  calculate_lis(*a);
  // Count non-LIS nodes
  push_count = 0;
  {
    t_node *tmp = *a;
    while (tmp) {
      if (!tmp->is_lis)
        push_count++;
      tmp = tmp->next;
    }
  }
  i = 0;
  // Push non-LIS nodes to B.
  // To avoid infinite rotation if all are LIS (already sorted logic catches
  // this but safety first) We bound the loop by original length to ensure we
  // check everyone once. Actually better: loop while push_count > 0. But simply
  // iterating len_a times is safer and simpler for Norminette (no complex
  // checks). Wait, if we rotate, the list changes head. We should just process
  // `len_a` times.
  while (i < len_a && push_count > 0) {
    if (!(*a)->is_lis) {
      pb(b, a, true);
      push_count--;
    } else {
      ra(a, true);
    }
    i++;
  }

  while (*b) {
    init_nodes_b(*a, *b);
    move_b_to_a(a, b);
  }
  current_index(*a);
  min_on_top(a);
}
