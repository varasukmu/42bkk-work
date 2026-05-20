/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasukmua <wrp.sukmuang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 04:55:35 by vasukmua          #+#    #+#             */
/*   Updated: 2026/05/21 05:23:37 by vasukmua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	easysort_3(t_list **stack)
{
	t_list	*max;
	t_list	*mid;
	t_list	*min;

	max = *stack;
	mid = max->next;
	min = mid->next;
	if (max->index > mid->index && max->index > min->index)
		ra(stack);
	else if (mid->index > max->index && mid->index > min->index)
		rra(stack);
	max = *stack;
	mid = max->next;
	if (max->index > mid->index)
		sa(stack);
}

void	easysort_4(t_list **stack_a, t_list **stack_b)
{
	int	pushed;

	pushed = 0;
	while (pushed < 1)
	{
		if ((*stack_a)->index == 0)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
			ra(stack_a);
	}
	easysort_3(stack_a);
	pa(stack_a, stack_b);
}

void	easysort_5(t_list **stack_a, t_list **stack_b)
{
	int	pushed;

	pushed = 0;
	while (pushed < 2)
	{
		if ((*stack_a)->index == 0 || (*stack_a)->index == 1)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
			ra(stack_a);
	}
	easysort_3(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a);
}
