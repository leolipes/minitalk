/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilipe- <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 20:58:52 by lfilipe-          #+#    #+#             */
/*   Updated: 2022/02/12 20:23:44 by lfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

static void	handler_signal(int signum, siginfo_t *info, void *context)
{
	static int	c = 255;
	static int	bits = 0;

	context = (void *)context;
	if (signum == SIGUSR2)
		c = c | (128 >> bits);
	else if (signum == SIGUSR1)
		c = c ^ (128 >> bits);
	++bits;
	if (bits == 8)
	{
		write(1, &c, 1);
		bits = 0;
		c = 255;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	s_signal;

	pid = getpid();
	sigemptyset(&s_signal.sa_mask);
	s_signal.sa_sigaction = handler_signal;
	s_signal.sa_flags = SA_SIGINFO | SA_RESTART;
	ft_printf("PID: %d\n", pid);
	sigaction(SIGUSR1, &s_signal, NULL);
	sigaction(SIGUSR2, &s_signal, NULL);
	while (1)
		pause();
}
