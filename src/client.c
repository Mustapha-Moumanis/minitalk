/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:40:35 by mmoumani          #+#    #+#             */
/*   Updated: 2023/01/29 16:49:46 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_send_bit(int pid, char c)
{
	int	i;

	i = 7;
	(void)pid;
	while (i >= 0)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(500);
	}
}

int main(int argc, char **argv)
{
	int		i;
	int		pid;
	char	*str;
	
	if (argc == 3)
	{
		i = 0;
		pid = ft_atoi(argv[1]);
		str = argv[2];
		while (str[i])
		{
			ft_send_bit(pid, str[i]);
			i++;	
		}
	}
}