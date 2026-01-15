/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro2019 <macbookpro2019@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 00:00:00 by macbookpro2       #+#    #+#             */
/*   Updated: 2026/01/15 00:06:00 by macbookpro2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static void free_arrays(int *arr, int *len_arr, int *prev_index) {
  free(arr);
  free(len_arr);
  free(prev_index);
}

static void mark_lis_nodes(t_node *stack, int *prev_index, int max_end_index) {
  int current_index;
  t_node *tmp;
  int i;

  if (max_end_index == -1)
    return;
  tmp = stack;
  while (tmp) {
    tmp->is_lis = false;
    tmp = tmp->next;
  }
  current_index = max_end_index;
  while (current_index != -1) {
    tmp = stack;
    i = 0;
    while (i < current_index) {
      tmp = tmp->next;
      i++;
    }
    tmp->is_lis = true;
    current_index = prev_index[current_index];
  }
}

static void fill_arrays(t_node *stack, int *arr, int size) {
  int i;

  i = 0;
  while (i < size) {
    arr[i] = stack->value;
    stack = stack->next;
    i++;
  }
}

static void compute_dp(int *arr, int *len_arr, int *prev_index, int size,
                       int *max_end_index) {
  int i;
  int j;
  int max_len;

  i = -1;
  while (++i < size) {
    len_arr[i] = 1;
    prev_index[i] = -1;
  }
  max_len = 1;
  *max_end_index = 0;
  i = 0;
  while (++i < size) {
    j = -1;
    while (++j < i) {
      if (arr[i] > arr[j] && len_arr[i] < len_arr[j] + 1) {
        len_arr[i] = len_arr[j] + 1;
        prev_index[i] = j;
      }
    }
    if (len_arr[i] > max_len) {
      max_len = len_arr[i];
      *max_end_index = i;
    }
  }
}

void calculate_lis(t_node *stack) {
  int size;
  int *arr;
  int *len_arr;
  int *prev_index;
  int max_end_index;

  size = stack_len(stack);
  if (size == 0)
    return;
  arr = malloc(sizeof(int) * size);
  len_arr = malloc(sizeof(int) * size);
  prev_index = malloc(sizeof(int) * size);
  if (!arr || !len_arr || !prev_index)
    return (free_arrays(arr, len_arr, prev_index));
  fill_arrays(stack, arr, size);
  compute_dp(arr, len_arr, prev_index, size, &max_end_index);
  mark_lis_nodes(stack, prev_index, max_end_index);
  free_arrays(arr, len_arr, prev_index);
}
