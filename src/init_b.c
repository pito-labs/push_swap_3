/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro2019 <macbookpro2019@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:00:00 by macbookpro2       #+#    #+#             */
/*   Updated: 2026/01/14 23:26:59 by macbookpro2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void set_target_b(t_node *a, t_node *b)
{
  t_node *current_a;
  t_node *target_node;
  long best_match_index;

  while (b) {
    best_match_index = LONG_MAX;
    current_a = a;
    while (current_a) {
      if (current_a->value > b->value && current_a->value < best_match_index) {
        best_match_index = current_a->value;
        target_node = current_a;
      }
      current_a = current_a->next;
    }
    if (best_match_index == LONG_MAX)
      b->target_node = find_min(a);
    else
      b->target_node = target_node;
    b = b->next;
  }
}

static void cost_analysis_b(t_node *a, t_node *b)
{
  int len_a;
  int len_b;

  len_a = stack_len(a);
  len_b = stack_len(b);
  while (b) {
    b->cost_b = b->index;
    if (!(b->above_median))
      b->cost_b = b->index - len_b;
    if (b->target_node->above_median)
      b->cost_a = b->target_node->index;
    else
      b->cost_a = b->target_node->index - len_a;
    b = b->next;
  }
}

// Re-doing cost_analysis to set 'push_cost'
// Helper Abs
static int ft_abs(int a)
{
  if (a < 0)
    return (-a);
  return (a);
}

static void set_final_cost(t_node *b)
{
  while (b) {
    // If both positive (top half) -> max(cost_a, cost_b)
    // If both negative (bottom half) -> max(abs(cost_a), abs(cost_b))
    // If mixed -> abs(cost_a) + abs(cost_b)
    if (b->cost_a > 0 && b->cost_b > 0)
      if (b->cost_a > b->cost_b)
        b->push_cost = b->cost_a;
      else
        b->push_cost = b->cost_b;
    else if (b->cost_a < 0 && b->cost_b < 0)
      if (ft_abs(b->cost_a) > ft_abs(b->cost_b))
        b->push_cost = ft_abs(b->cost_a);
      else
        b->push_cost = ft_abs(b->cost_b);
    else
      b->push_cost = ft_abs(b->cost_a) + ft_abs(b->cost_b);
    b = b->next;
  }
}

// Helper to find cheapest after setting costs
static void mark_cheapest_node(t_node *b)
{
  long cheapest_val;
  t_node *cheapest_node;

  if (!b)
    return;
  cheapest_val = LONG_MAX;
  while (b)
  {
    if (b->push_cost < cheapest_val) 
    {
      cheapest_val = b->push_cost;
      cheapest_node = b;
    }
    b = b->next;
  }
  cheapest_node->cheapest = true;
}

void init_nodes_b(t_node *a, t_node *b)
{
  current_index(a);
  current_index(b);
  set_target_b(a, b);
  cost_analysis_b(a, b);
  set_final_cost(b);
  mark_cheapest_node(b);
}
