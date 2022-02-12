/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 20:58:57 by lfilipe-          #+#    #+#             */
/*   Updated: 2022/02/11 00:41:58 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

int	g_status;

static void	handler(int signum)
{
	g_status = 1;
	signum = (int)signum;
}

static void	send_signals(pid_t pid, char *str)
{
	int	i;
	int	shift;

	i = 0;
	while (str[i])
	{
		shift = 0;
		while (shift <= 7)
		{
			if (str[i] & 128 >> shift)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			g_status = 0;
			usleep(0.09 * 1000000);
			++shift;
		}
		++i;
	}
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		res;
	int		sign;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return ((int)(res * sign));
}

void	print_error(void)
{
	ft_printf("Invalid arguments!\n");
	ft_printf("You must send:\n./client <PID> <menssage>\n");
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	s_signal;

	if (argc != 3)
		print_error();
	pid = ft_atoi(argv[1]);
	if (!pid)
		print_error();
	sigemptyset(&s_signal.sa_mask);
	s_signal.sa_handler = &handler;
	s_signal.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &s_signal, NULL);
	send_signals(pid, argv[2]);
	return (0);
}
