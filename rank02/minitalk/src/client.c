/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasukmua <wrp.sukmuang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 20:17:26 by vasukmua          #+#    #+#             */
/*   Updated: 2026/05/06 02:26:02 by vasukmua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

int	g_recieved;

void	recieved(int sig, siginfo_t *info, void *context)
{
	(void) info;
	(void) context;
	if (sig == SIGUSR1)
		g_recieved = 1;
}

void	send_char(int server_pid, char ch)
{
	int		i;

	i = 7;
	while (i >= 0)
	{
		g_recieved = 0;
		if ((ch >> i) & 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		while (!g_recieved)
			pause();
		i--;
	}
}

void	send_word(int server_pid, char *word)
{
	int		i;

	i = 0;
	while (word[i])
	{
		send_char(server_pid, word[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	pid_t				server_pid;

	g_recieved = 0;
	server_pid = atoi(av[1]);
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = &recieved;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	if (ac != 3)
	{
		ft_putstr("./client <pid> <message>");
		return (1);
	}
	send_word(server_pid, av[2]);
	return (0);
}
