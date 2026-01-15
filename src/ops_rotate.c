/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro2019 <macbookpro2019@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:00:00 by macbookpro2       #+#    #+#             */
/*   Updated: 2026/01/14 23:39:28 by macbookpro2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rotate(t_node **stack)
{
  t_node *last_node;
  int len;

  len = stack_len(*stack);
  if (!*stack || !(*stack)->next || len < 2)
    return;
  last_node = find_last(*stack);
  last_node->next = *stack;
  *stack = (*stack)->next;
  (*stack)->prev = NULL;
  last_node->next->prev = last_node;
  last_node->next->next = NULL;
}

void ra(t_node **a, bool print)
{
  rotate(a);
  if (print)
    write(1, "ra\n", 3);
}

void rb(t_node **b, bool print)
{
  rotate(b);
  if (print)
    write(1, "rb\n", 3);
}

void rr(t_node **a, t_node **b, bool print)
{
  rotate(a);
  rotate(b);
  if (print)
    write(1, "rr\n", 3);
}
