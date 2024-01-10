/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xX.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:10:00 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/07/24 13:48:13 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexp(unsigned int x)
{
	int		i;
	char	buff[30];
	char	*base;
	int		j;

	i = 0;
	base = "0123456789abcdef";
	if (x == 0 || x == (unsigned int)LONG_MIN)
	{
		ft_putchar('0');
		return (1);
	}
	while (x != 0)
	{
		buff[i] = base[x % 16];
		x = x / 16;
		i++;
	}
	j = i;
	while (i > 0)
		ft_putchar(buff[i-- - 1]);
	return (j);
}

int	hexp2(unsigned int x)
{
	int		i;
	char	buff[30];
	char	*base;
	int		j;

	i = 0;
	base = "0123456789ABCDEF";
	if (x == 0 || x == (unsigned int)LONG_MIN)
	{
		ft_putchar('0');
		return (1);
	}
	while (x != 0)
	{
		buff[i] = base[x % 16];
		x = x / 16;
		i++;
	}
	j = i;
	while (i > 0)
		ft_putchar(buff[i-- - 1]);
	return (j);
}
