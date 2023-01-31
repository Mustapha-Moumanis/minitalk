/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:40:32 by mmoumani          #+#    #+#             */
/*   Updated: 2023/01/31 08:28:42 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

void	print_msg(int sig, struct __siginfo *info, void *test)
{
	static int				i;
	static unsigned char	c;

	(void)test;
	if (sig == SIGUSR1)
		c |= 1;
	if (i++ == 7)
	{
		ft_putchar(c);
		usleep(1000);
		kill(info->si_pid, SIGUSR2);
		i = 0;
		c = 0;
	}
	c <<= 1;
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	rest;

	(void)argv;
	if (argc != 1)
		ft_error("You need no arguments here.\n");
	rest.sa_sigaction = print_msg;
	pid = getpid();
	write (1, "PID : ", 7);
	ft_putnbr(pid, 1);
	ft_putchar('\n');
	sigaction(SIGUSR1, &rest, NULL);
	sigaction(SIGUSR2, &rest, NULL);
	while (1)
		pause();
}
