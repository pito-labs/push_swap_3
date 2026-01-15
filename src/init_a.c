/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro2019 <macbookpro2019@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:00:00 by macbookpro2       #+#    #+#             */
/*   Updated: 2026/01/14 23:27:49 by macbookpro2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void current_index(t_node *stack)
{
  int i;
  int median;

  if (!stack)
    return;
  i = 0;
  median = stack_len(stack) / 2;
  while (stack)
  {
    stack->index = i;
    if (i <= median)
      stack->above_median = true;
    else
      stack->above_median = false;
    stack = stack->next;
    i++;
  }
}

// Actually, let's implement the Cost Analysis for B -> A here or in init_b.
// For A, we mostly need current_index, and prep functions.

void init_nodes_a(t_node *a, t_node *b)
{
  current_index(a);
  current_index(b);
  // target logic usually B->A
  (void)b; // unused for now
}
