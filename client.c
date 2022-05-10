/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:02:12 by ooumlil           #+#    #+#             */
/*   Updated: 2022/03/30 20:56:24 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

	if (ac != 3 || av[2] == '\0')
	{
		ft_putstr("usage : ./client [pid] 'text to send'");
		exit (1);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 1)
	{
		ft_putstr("error\n");
		exit (1);
	}
	shifting(pid, av[2]);
}
