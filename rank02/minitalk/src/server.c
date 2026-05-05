/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasukmua <wrp.sukmuang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 20:17:18 by vasukmua          #+#    #+#             */
/*   Updated: 2026/05/05 00:56:07 by vasukmua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	handler(int sig, siginfo_t *info, void *context)
{
	static int	bit;
	static char	ch;

	(void) context;
	ch <<= 1;
	if (sig == SIGUSR1)
		ch |= 1;
	bit++;
	if (bit == 8)
	{
		write(1, &ch, 1);
		bit = 0;
		ch = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = getpid();
	ft_putstr("Server PID : ");
	ft_putnum(pid);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
