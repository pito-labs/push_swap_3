/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro2019 <macbookpro2019@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:00:00 by macbookpro2       #+#    #+#             */
/*   Updated: 2026/01/14 23:39:43 by macbookpro2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void swap(t_node **head)
{
  int len;

  len = stack_len(*head);
  if (NULL == *head || NULL == (*head)->next || len < 2)
    return;
  *head = (*head)->next;
  (*head)->prev->prev = *head;
  (*head)->prev->next = (*head)->next;
  if ((*head)->next)
    (*head)->next->prev = (*head)->prev;
  (*head)->next = (*head)->prev;
  (*head)->prev = NULL;
}

void sa(t_node **a, bool print)
{
  swap(a);
  if (print)
    write(1, "sa\n", 3);
}

void sb(t_node **b, bool print)
{
  swap(b);
  if (print)
    write(1, "sb\n", 3);
}

void ss(t_node **a, t_node **b, bool print)
{
  swap(a);
  swap(b);
  if (print)
    write(1, "ss\n", 3);
}
