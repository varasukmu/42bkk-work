/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasukmua <wrp.sukmuang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 04:08:10 by vasukmua          #+#    #+#             */
/*   Updated: 2026/05/21 16:04:38 by vasukmua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_atob(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	chunk;
	int	size;

	i = 0;
	size = ft_lstsize(*stack_a);
	chunk = get_chunk(size);
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			i++;
		}
		else if ((*stack_a)->index <= i + chunk)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else
			ra(stack_a);
	}
}

void	sort_btoa(t_list **stack_a, t_list **stack_b)
{
	int	max_index;
	int	pos;
	int	size;

	while (*stack_b)
	{
		size = ft_lstsize(*stack_b);
		max_index = size - 1;
		pos = get_pos(*stack_b, max_index);
		if (pos == 0)
			pa(stack_a, stack_b);
		else if (pos <= size / 2)
			rb(stack_b);
		else
			rrb(stack_b);
	}
}

int	is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}
