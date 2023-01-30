/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:40:35 by mmoumani          #+#    #+#             */
/*   Updated: 2023/01/30 20:17:17 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include "../includes/minitalk_bonus.h"

int	check_pid(char *str)
{
	int i;

	i = 0;
	if (!str[0])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_send_bit(int pid, char c)
{
	int	i;

	i = 7;
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
		if (!check_pid(argv[1]) || !argv[2][0])
			ft_error("invalid pid or empty arg\n");
		pid = ft_atoi(argv[1]);
		if (kill(pid, 0) || pid == 0)
			ft_error("invalid pid\n");
		str = argv[2];
		while (str[i])
		{
			ft_send_bit(pid, str[i]);
			i++;
		}
		ft_send_bit(pid, '\n');
	}
	else
		ft_error("you need 2 arg\n");
}
