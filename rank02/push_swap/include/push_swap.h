/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasukmua <wrp.sukmuang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 18:21:43 by vasukmua          #+#    #+#             */
/*   Updated: 2026/05/21 05:21:54 by vasukmua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "struct.h"

// Stack Functions
void	free_stack(t_list **stack);
t_list	*ft_lstnew(int value);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	init_stack(t_list **stack, char **argvs);

// Parse and Utils
int		check_num(char **argvs);
int		check_dup(t_list *stack);
long	ft_atoi_long(const char *str);
char	**ft_split(char const *s, char c);
void	ft_putstr(char *str);

// Helper
void	free_argvs(char **argvs);
void	assign_index(t_list *stack);
int		ft_lstsize(t_list *lst);
int		get_chunk(int size);
int		get_pos(t_list *stack, int target_index);

// Core Operations
void	push(t_list **src, t_list **dest);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);

// Wrapper Operations
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	swap(t_list **stack);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
int		is_sorted(t_list *stack);
void	easysort_3(t_list **stack);
void	easysort_4(t_list **stack_a, t_list **stack_b);
void	easysort_5(t_list **stack_a, t_list **stack_b);

// Sort Algorithms
void	sort_atob(t_list **stack_a, t_list **stack_b);
void	sort_btoa(t_list **stack_a, t_list **stack_b);
void	do_sort(t_list **stack_a, t_list **stack_b, int size);
#endif