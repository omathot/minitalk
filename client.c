/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscarmathot <oscarmathot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 15:31:42 by oscarmathot       #+#    #+#             */
/*   Updated: 2023/05/31 16:39:35 by oscarmathot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	decoder(unsigned char str, int pid)
{
	int				i;
	unsigned int	base;

	i = 8;
	base = 128;
	while (i > 0)
	{
		if (str < base)
		{
			ft_printf("0");
			kill(pid, SIGUSR1);
		}
		else
		{
			ft_printf("1");
			kill(pid, SIGUSR2);
			str = str - base;
		}
		base = base / 2;
		i--;
		usleep(200);							// stop losing signals/mixing up ordering when sent too fast
	}
}

int	main(int argc, char **argv)
{
	int	counter;
	int	pid;

	counter = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid < 0)
		{
			ft_printf("Invalid PID value\n");
			exit(EXIT_SUCCESS);
		}
		while (argv[2][counter])
		{
			decoder(argv[2][counter], pid);
			ft_printf("\n");
			counter++;
		}
		decoder('\n', pid);
	}
	else
		ft_printf("Usage: ./client <server_pid> <string here>\n");
	return (0);
}
