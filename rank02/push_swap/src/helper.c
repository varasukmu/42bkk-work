/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasukmua <wrp.sukmuang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 03:17:23 by vasukmua          #+#    #+#             */
/*   Updated: 2026/05/21 16:16:37 by vasukmua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_chunk(int size)
{
	int	chunk;

	if (size <= 100)
		chunk = 15;
	else if (size <= 180)
		chunk = 20;
	else if (size <= 400)
		chunk = 30;
	else if (size <= 500)
		chunk = 35;
	else
		chunk = 50;
	return (chunk);
}

int	get_pos(t_list *stack, int target_index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == target_index)
			break ;
		pos++;
		stack = stack->next;
	}
	return (pos);
}

void	assign_index(t_list *stack)
{
	t_list	*current;
	t_list	*compare;
	int		count;

	current = stack;
	while (current)
	{
		count = 0;
		compare = stack;
		while (compare)
		{
			if (current->nbr > compare->nbr)
				count++;
			compare = compare->next;
		}
		current->index = count;
		current = current->next;
	}
}

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

void	free_argvs(char **argvs)
{
	int	i;

	i = 0;
	while (argvs[i])
	{
		free(argvs[i]);
		i++;
	}
	free(argvs);
}
