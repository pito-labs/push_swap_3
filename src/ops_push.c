/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro2019 <macbookpro2019@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:00:00 by macbookpro2       #+#    #+#             */
/*   Updated: 2026/01/14 23:38:47 by macbookpro2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push(t_node **dest, t_node **src)
{
  t_node *push_node;

  if (!*src)
    return;
  push_node = *src;
  *src = (*src)->next;
  if (*src)
    (*src)->prev = NULL;
  push_node->prev = NULL;
  if (!*dest)
  {
    *dest = push_node;
    push_node->next = NULL;
  } else
  {
    push_node->next = *dest;
    push_node->next->prev = push_node;
    *dest = push_node;
  }
}

void pa(t_node **a, t_node **b, bool print)
{
  push(a, b);
  if (print)
    write(1, "pa\n", 3);
}

void pb(t_node **b, t_node **a, bool print)
{
  push(b, a);
  if (print)
    write(1, "pb\n", 3);
}
