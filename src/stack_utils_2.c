/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro2019 <macbookpro2019@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:00:00 by macbookpro2       #+#    #+#             */
/*   Updated: 2026/01/14 23:41:34 by macbookpro2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *get_cheapest(t_node *stack)
{
  if (!stack)
    return (NULL);
  while (stack)
  {
    if (stack->cheapest)
      return (stack);
    stack = stack->next;
  }
  return (NULL);
}

void prep_for_push(t_node **stack, t_node *top_node, char stack_name)
{
  while (*stack != top_node)
  {
    if (stack_name == 'a')
    {
      if (top_node->above_median)
        ra(stack, true);
      else
        rra(stack, true);
    }
    else if (stack_name == 'b')
    {
      if (top_node->above_median)
        rb(stack, true);
      else
        rrb(stack, true);
    }
  }
}
