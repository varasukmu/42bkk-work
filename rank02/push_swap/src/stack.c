/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasukmua <wrp.sukmuang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 19:36:04 by vasukmua          #+#    #+#             */
/*   Updated: 2026/05/21 05:09:13 by vasukmua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_stack(t_list **stack)
{
	t_list	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

t_list	*ft_lstnew(int value)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->nbr = value;
	new->index = -1;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
}

void	init_stack(t_list **stack, char **argvs)
{
	int		i;
	long	num;
	t_list	*new_node;

	i = 0;
	while (argvs[i])
	{
		num = ft_atoi_long(argvs[i]);
		if (num > 2147483647 || num < -2147483648)
		{
			free_stack(stack);
			free_argvs(argvs);
			write(2, "Error\n", 6);
			exit(1);
		}
		new_node = ft_lstnew((int)num);
		if (!new_node)
		{
			free_stack(stack);
			free_argvs(argvs);
			exit(1);
		}
		ft_lstadd_back(stack, new_node);
		i++;
	}
}
