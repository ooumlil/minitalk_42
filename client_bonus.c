/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 22:27:07 by ooumlil           #+#    #+#             */
/*   Updated: 2022/03/29 19:42:43 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_confirmation(int sig)
{
	if (sig == 30)
		ft_putstr("Message Sent!\n");
}

void	shifting(int pid, char *s)
{
	int	i;
	int	bit;

	i = 0;
	if (!s)
		exit(1);
	while (1)
	{
		bit = -1;
		while (++bit < 9)
		{
			if (s[i] & (128 >> bit))
			{
				if (kill(pid, 30) == -1)
					exit(1);
			}
			else
				if (kill(pid, 31) == -1)
					exit(1);
			usleep(500);
		}
		if (!s[i])
			break ;
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3 || av[2][0] == '\0')
	{
		write (1, "usage : ./client [pid] 'text to send'", 37);
		exit (1);
	}
	signal(30, ft_confirmation);
	pid = ft_atoi(av[1]);
	if (pid <= 1)
	{
		write (1, "error\n", 6);
		exit (1);
	}
	shifting(pid, av[2]);
}
