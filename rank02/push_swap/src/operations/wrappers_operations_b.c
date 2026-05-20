/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers_operations_b.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasukmua <wrp.sukmuang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 04:06:34 by vasukmua          #+#    #+#             */
/*   Updated: 2026/05/21 05:03:46 by vasukmua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr("pb\n");
}

void	rb(t_list **stack_b)
{
	rotate(stack_b);
	ft_putstr("rb\n");
}

void	sb(t_list **stack_b)
{
	swap(stack_b);
	ft_putstr("sb\n");
}

void	rrb(t_list **stack_b)
{
	reverse_rotate(stack_b);
	ft_putstr("rrb\n");
}
