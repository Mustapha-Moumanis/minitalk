/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:11:56 by mmoumani          #+#    #+#             */
/*   Updated: 2023/01/30 14:43:06 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include "../includes/minitalk_bonus.h"

int	ft_putnbr(int n, int i)
{
	long	temp;

	if (n < 0)
	{
		i += ft_putchar('-');
		temp = (-(long) n);
	}
	else
		temp = n;
	if (temp < 10)
		ft_putchar(temp + '0');
	else
	{
		i += ft_putnbr(temp / 10, 1);
		ft_putchar(temp % 10 + '0');
	}
	return (i);
}
