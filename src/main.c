/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro2019 <macbookpro2019@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:00:00 by macbookpro2       #+#    #+#             */
/*   Updated: 2026/01/14 23:37:57 by macbookpro2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
  t_node *a;
  t_node *b;

  a = NULL;
  b = NULL;
  if (argc == 1 || (argc == 2 && !argv[1][0]))
    return (1);
  if (argc == 2)
    stack_init(&a, ft_split(argv[1], ' '), true);
  else
    stack_init(&a, argv + 1, false);
  if (!stack_sorted(a))
  {
    if (stack_len(a) == 2)
      sa(&a, true);
    else if (stack_len(a) == 3)
      sort_three(&a);
    else
      sort_stacks(&a, &b);
  }
  free_stack(&a);
  return (0);
}
