/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro2019 <macbookpro2019@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:00:00 by macbookpro2       #+#    #+#             */
/*   Updated: 2026/01/14 23:43:14 by macbookpro2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int count_words(char const *str, char c)
{
  int count;
  int i;

  i = 0;
  count = 0;
  while (str[i])
  {
    while (str[i] == c)
      i++;
    if (str[i])
      count++;
    while (str[i] && str[i] != c)
      i++;
  }
  return (count);
}

static char *get_next_word(char const *str, char c, int *cursor)
{
  char *word;
  int len;
  int i;

  len = 0;
  while (str[*cursor] == c)
    (*cursor)++;
  while (str[*cursor + len] && str[*cursor + len] != c)
    len++;
  word = malloc(sizeof(char) * (len + 1));
  if (!word)
    return (NULL);
  i = 0;
  while (i < len)
  {
    word[i] = str[*cursor + i];
    i++;
  }
  word[i] = '\0';
  *cursor += len;
  return (word);
}

static void free_split(char **split_arr, int words)
{
  int i;

  i = 0;
  while (i < words)
  {
    free(split_arr[i]);
    i++;
  }
  free(split_arr);
}

char **ft_split(char const *s, char c)
{
  char **res;
  int words;
  int i;
  int cursor;

  if (!s)
    return (NULL);
  words = count_words(s, c);
  res = malloc(sizeof(char *) * (words + 2));
  if (!res)
    return (NULL);
  i = 0;
  cursor = 0;
  while (i < words)
  {
    res[i] = get_next_word(s, c, &cursor);
    if (!res[i])
    {
      free_split(res, i);
      return (NULL);
    }
    i++;
  }
  res[i] = NULL;
  return (res);
}
