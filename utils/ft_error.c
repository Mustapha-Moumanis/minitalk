/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:09:34 by mmoumani          #+#    #+#             */
/*   Updated: 2023/01/31 08:25:25 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include "../includes/minitalk_bonus.h"

void	ft_error(char *str)
{
	write(2, "Error\n", 7);
	write(1, str, ft_strlen(str));
	exit(1);
}
