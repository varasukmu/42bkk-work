/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasukmua <wrp.sukmuang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 17:39:46 by vasukmua          #+#    #+#             */
/*   Updated: 2026/05/21 16:16:31 by vasukmua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	do_sort(t_list **stack_a, t_list **stack_b, int size)
{
	assign_index(*stack_a);
	if (is_sorted(*stack_a))
		return ;
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		easysort_3(stack_a);
	else if (size == 4)
		easysort_4(stack_a, stack_b);
	else if (size == 5)
		easysort_5(stack_a, stack_b);
	else
	{
		sort_atob(stack_a, stack_b);
		sort_btoa(stack_a, stack_b);
	}
}

int	prepare(t_list **stack, int ac, char **av)
{
	char	**argvs;
	int		i;

	i = 1;
	while (i < ac)
	{
		argvs = ft_split(av[i], ' ');
		if (!argvs || !argvs[0] || !check_num(argvs))
		{
			write(2, "Error\n", 6);
			if (argvs)
				free_argvs(argvs);
			return (0);
		}
		init_stack(stack, argvs);
		free_argvs(argvs);
		i++;
	}
	if (!check_dup(*stack))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	if (!prepare(&stack_a, ac, av))
	{
		free_stack(&stack_a);
		return (-1);
	}
	size = ft_lstsize(stack_a);
	do_sort(&stack_a, &stack_b, size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

//void	print_stack_index(t_list *stack)
//{
//	if (!stack)
//	{
//		printf("Stack is empty!\n");
//		return ;
//	}
//	while (stack)
//	{
//		printf("[%d] -> Index: %d\n", stack->nbr, stack->index);
//		stack = stack->next;
//	}
//	printf("\n");
//}
