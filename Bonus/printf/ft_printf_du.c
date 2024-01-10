/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_du.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:01:52 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/07/24 15:37:32 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	dec(int x)
{
	int	y;
	int	i;

	y = x;
	i = 0;
	ft_putnbr(x);
	if (x == 0)
		return (1);
	if (y < 0)
	{
		y = y * -1;
		i++;
	}
	while (y != 0)
	{
		y = y / 10;
		i++;
	}
	return (i);
}

int	dec2(unsigned int x)
{
	unsigned int	y;
	int				i;

	y = x;
	i = 0;
	ft_putnbru(x);
	if (x == 0 || x == (unsigned int)LONG_MIN)
		return (1);
	while (y != 0)
	{
		y = y / 10;
		i++;
	}
	return (i);
}
