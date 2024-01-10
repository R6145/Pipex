/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 18:50:07 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/07/24 16:14:54 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pontp(unsigned long long x)
{
	int		i;
	char	buff[30];
	char	*base;
	int		j;

	i = 0;
	base = "0123456789abcdef";
	ft_putstr("0x");
	if (x == 0)
	{
		ft_putchar('0');
		return (3);
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
	return (j + 2);
}
