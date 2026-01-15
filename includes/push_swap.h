/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro2019 <macbookpro2019@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:00:00 by macbookpro2       #+#    #+#             */
/*   Updated: 2026/01/15 00:02:54 by macbookpro2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_node {
  int value;
  int index;
  int push_cost;
  int cost_a;
  int cost_b;
  bool above_median;
  bool cheapest;
  bool is_lis;

  struct s_node *target_node;
  struct s_node *next;
  struct s_node *prev;
} t_node;

/* Stack Utils */
void stack_init(t_node **a, char **argv, bool split_argc);
void init_nodes_a(t_node *a, t_node *b);
void init_nodes_b(t_node *a, t_node *b);
void current_index(t_node *stack);

t_node *get_cheapest(t_node *stack);
void prep_for_push(t_node **stack, t_node *top_node, char stack_name);
int stack_len(t_node *stack);
t_node *find_last(t_node *stack);
bool stack_sorted(t_node *stack);
t_node *find_min(t_node *stack);
t_node *find_max(t_node *stack);
void free_stack(t_node **stack);
void free_errors(t_node **a);

/* Commands */
void sa(t_node **a, bool print);
void sb(t_node **b, bool print);
void ss(t_node **a, t_node **b, bool print);
void pa(t_node **a, t_node **b, bool print);
void pb(t_node **b, t_node **a, bool print);
void ra(t_node **a, bool print);
void rb(t_node **b, bool print);
void rr(t_node **a, t_node **b, bool print);
void rra(t_node **a, bool print);
void rrb(t_node **b, bool print);
void rrr(t_node **a, t_node **b, bool print);

/* Algorithm */
void sort_three(t_node **a);
void sort_stacks(t_node **a, t_node **b);
void calculate_lis(t_node *stack);

/* Utils */
long ft_atol(const char *str);
char **ft_split(char const *s, char c);

#endif
