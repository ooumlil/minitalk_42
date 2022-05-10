/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 22:26:18 by ooumlil           #+#    #+#             */
/*   Updated: 2022/03/30 20:52:19 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_sign(int pid, int sig)
{
	if (kill(pid, sig) == -1)
		exit(1);
}

void	handler(int sig, siginfo_t *data, void *useless)
{
	static int	pid;
	static char	c = 0xFF;
	static int	bit;

	(void) useless;
	if (pid != data->si_pid)
	{
		c = 0xFF;
		bit = 0;
		pid = data->si_pid;
	}
	if (sig == 30)
		c |= 0x80 >> bit;
	else if (sig == 31)
		c ^= 0x80 >> bit;
	if (bit++ == 8)
	{
		if (!c)
			ft_sign(pid, 30);
		ft_putchar(c);
		bit = 0;
		c = 0xFF;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	(void)av;
	if (ac != 1)
	{
		ft_putstr("Run ./server_bonus thats it\n");
		return (1);
	}
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(30, &sa, NULL);
	sigaction(31, &sa, NULL);
	ft_putnbr(getpid());
	ft_putchar('\n');
	while (1)
		pause();
}
