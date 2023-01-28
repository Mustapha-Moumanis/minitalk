/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:40:35 by mmoumani          #+#    #+#             */
/*   Updated: 2023/01/28 01:25:56 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void print_bits(unsigned char octet)
{
	int	i = 8;
	unsigned char 	bit;

	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}

unsigned char swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}

void	ft_send_msg(char  c, int pid)
{
	(void)pid;
	print_bits(c);
	write(1, "\n", 1);
	print_bits(swap_bits(c));

	// kill();
}

int main(int argc, char **argv)
{
	int     pid;
	int     i;
	char    *str;
	
	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
		while (str[i])
		{
			ft_send_msg(str[i], pid);
			i++;
		}
		
	}
}