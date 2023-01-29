/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:40:32 by mmoumani          #+#    #+#             */
/*   Updated: 2023/01/29 19:35:17 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	p_bits(char	c)
{
	int i = 7;
	while (i > 0)
	{
		if (c & (1 << i))
			printf("1");
		else
			printf("0");
		i--;
	}
	printf("\n");
}

void	print_msg(int sig)
{
	static int	i;
	static char	c;

	if (sig == SIGUSR1)
		c |= 1;
	if (i++ == 7)
	{
		write (1, &c, 1);
		i = 0;
		c = 0;
	}
	c <<= 1;
}

int main(void)
{
	int pid;
	pid = getpid();

	printf("%d\n", pid);
	while (1)
	{
		signal(SIGUSR1, print_msg);
		signal(SIGUSR2, print_msg);
		pause();
	}

}