/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers_operations_a.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasukmua <wrp.sukmuang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 04:06:34 by vasukmua          #+#    #+#             */
/*   Updated: 2026/05/21 05:03:45 by vasukmua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
	ft_putstr("pa\n");
}

void	ra(t_list **stack_a)
{
	rotate(stack_a);
	ft_putstr("ra\n");
}

void	sa(t_list **stack_a)
{
	swap(stack_a);
	ft_putstr("sa\n");
}

void	rra(t_list **stack_a)
{
	reverse_rotate(stack_a);
	ft_putstr("rra\n");
}
