/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro2019 <macbookpro2019@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:00:00 by macbookpro2       #+#    #+#             */
/*   Updated: 2026/01/14 23:42:16 by macbookpro2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stack_len(t_node *stack)
{
  int count;

  if (!stack)
    return (0);
  count = 0;
  while (stack)
  {
    stack = stack->next;
    count++;
  }
  return (count);
}

t_node *find_last(t_node *stack)
{
  if (!stack)
    return (NULL);
  while (stack->next)
    stack = stack->next;
  return (stack);
}

bool stack_sorted(t_node *stack)
{
  if (!stack)
    return (1);
  while (stack->next)
  {
    if (stack->value > stack->next->value)
      return (false);
    stack = stack->next;
  }
  return (true);
}

t_node *find_min(t_node *stack)
{
  long min;
  t_node *min_node;

  if (!stack)
    return (NULL);
  min = LONG_MAX;
  while (stack)
  {
    if (stack->value < min)
    {
      min = stack->value;
      min_node = stack;
    }
    stack = stack->next;
  }
  return (min_node);
}

t_node *find_max(t_node *stack)
{
  long max;
  t_node *max_node;

  if (!stack)
    return (NULL);
  max = LONG_MIN;
  while (stack)
  {
    if (stack->value > max)
    {
      max = stack->value;
      max_node = stack;
    }
    stack = stack->next;
  }
  return (max_node);
}
