/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscarmathot <oscarmathot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:43:36 by oscarmathot       #+#    #+#             */
/*   Updated: 2023/05/31 12:51:38 by oscarmathot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	decoder(int sig, siginfo_t *info, void *context)
{
	static int	counter = 0;
	static char	c = 0;

	(void)info;
	(void)context;
	if (sig == SIGUSR2)
		c = c | 128 >> counter;
	counter++;
	if (counter == 8)
	{
		write(1, &c, 1);
		c = 0;
		counter = 0;
	}
}

int	main(void)
{
	struct sigaction	sa1;
	struct sigaction	sa2;
	pid_t				my_pid;

	my_pid = getpid();
	ft_printf("Server PID is %d\n", (int)my_pid);
	sa1.sa_flags = SA_SIGINFO;
	sa1.sa_sigaction = decoder;
	sigaction(SIGUSR1, &sa1, NULL);
	sa2.sa_flags = SA_SIGINFO;
	sa2.sa_sigaction = decoder;
	sigaction(SIGUSR2, &sa2, NULL);
	while (1)
		sleep(5);
	return (0);
}
