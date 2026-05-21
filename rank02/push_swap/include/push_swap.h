/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasukmua <wrp.sukmuang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 18:21:43 by vasukmua          #+#    #+#             */
/*   Updated: 2026/05/21 16:39:49 by vasukmua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "struct.h"

void	easysort_3(t_list **stack);
void	easysort_4(t_list **stack_a, t_list **stack_b);
void	easysort_5(t_list **stack_a, t_list **stack_b);

int		get_chunk(int size);
int		get_pos(t_list *stack, int target_index);
void	assign_index(t_list *stack);
void	free_stack(t_list **stack);
void	free_argvs(char **argvs);

void	do_sort(t_list **stack_a, t_list **stack_b, int size);
int		prepare(t_list **stack, int ac, char **av);

int		check_num(char **argvs);
int		check_dup(t_list *stack);
long	ft_atoi_long(const char *str);

void	sort_atob(t_list **stack_a, t_list **stack_b);
void	sort_btoa(t_list **stack_a, t_list **stack_b);
int		is_sorted(t_list *stack);

char	**ft_split(char const *s, char c);

int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew(int value);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	init_stack(t_list **stack, char **argvs);

void	push(t_list **src, t_list **dest);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);
void	swap(t_list **stack);
void	ft_putstr(char *str);

void	pa(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	sa(t_list **stack_a);
void	rra(t_list **stack_a);
void	pb(t_list **stack_a, t_list **stack_b);
void	rb(t_list **stack_b);
void	sb(t_list **stack_b);
void	rrb(t_list **stack_b);

#endif