/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasukmua <wrp.sukmuang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 03:27:57 by vasukmua          #+#    #+#             */
/*   Updated: 2026/05/21 16:09:27 by vasukmua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_num(char **argvs)
{
	int	i;
	int	j;

	i = 0;
	while (argvs[i])
	{
		j = 0;
		if (argvs[i][j] == '-' || argvs[i][j] == '+')
			j++;
		if (argvs[i][j] == '\0')
			return (0);
		while (argvs[i][j])
		{
			if (argvs[i][j] < '0' || argvs[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_dup(t_list *stack)
{
	t_list	*tmp;

	while (stack)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (stack->nbr == tmp->nbr)
				return (0);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (1);
}

long	ft_atoi_long(const char *str)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && res <= 2147483648)
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * sign);
}
