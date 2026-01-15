/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_atol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro2019 <macbookpro2019@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:00:00 by macbookpro2       #+#    #+#             */
/*   Updated: 2026/01/14 23:42:27 by macbookpro2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long ft_atol(const char *str)
{
  long res;
  int sign;
  int i;

  res = 0;
  sign = 1;
  i = 0;
  while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
    i++;
  if (str[i] == '-' || str[i] == '+')
  {
    if (str[i] == '-')
      sign = -1;
    i++;
  }
  while (str[i] >= '0' && str[i] <= '9')
  {
    res = res * 10 + (str[i] - '0');
    i++;
  }
  return (res * sign);
}
