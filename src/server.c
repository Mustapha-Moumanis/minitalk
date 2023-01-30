/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:40:32 by mmoumani          #+#    #+#             */
/*   Updated: 2023/01/30 20:24:13 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	print_msg(int sig)
{
	static int	i;
	static char	c;

	if (sig == SIGUSR1)
		c |= 1;
	if (i++ == 7)
	{
		ft_putchar(c);
		i = 0;
		c = 0;
	}
	c <<= 1;
}

int main(int argc, char **argv)
{
	int pid;
	
	(void)argv;
	if (argc != 1)
		ft_error("you don't need arguments here\n");
	pid = getpid();
	ft_putnbr(pid, 1);
	ft_putchar('\n');
	signal(SIGUSR1, print_msg);
	signal(SIGUSR2, print_msg);
	while (1)
	{
		pause();
	}
}