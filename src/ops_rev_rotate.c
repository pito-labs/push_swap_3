/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro2019 <macbookpro2019@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:00:00 by macbookpro2       #+#    #+#             */
/*   Updated: 2026/01/14 23:39:04 by macbookpro2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rev_rotate(t_node **stack)
{
  t_node *last;
  int len;

  len = stack_len(*stack);
  if (!*stack || !(*stack)->next || len < 2)
    return;
  last = find_last(*stack);
  last->prev->next = NULL;
  last->next = *stack;
  last->prev = NULL;
  (*stack)->prev = last;
  *stack = last;
}

void rra(t_node **a, bool print)
{
  rev_rotate(a);
  if (print)
    write(1, "rra\n", 4);
}

void rrb(t_node **b, bool print)
{
  rev_rotate(b);
  if (print)
    write(1, "rrb\n", 4);
}

void rrr(t_node **a, t_node **b, bool print)
{
  rev_rotate(a);
  rev_rotate(b);
  if (print)
    write(1, "rrr\n", 4);
}
