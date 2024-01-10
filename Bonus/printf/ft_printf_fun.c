/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fun.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 18:50:02 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/12/24 18:05:54 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen2(const char *ch)
{
	int	i;

	i = 0;
	while (ch[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_putstr(char *s)
{
	if (s)
		write(1, s, ft_strlen2(s));
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
	}
	if (n < 10)
	{
		ft_putchar(n + '0');
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

void	ft_putnbru(unsigned long int n)
{
	if (n == (unsigned long)LONG_MIN)
	{
		ft_putchar('0');
	}
	else if (n > 4294967295)
	{
		ft_putchar('4');
		ft_putnbru(294967295);
	}
	else if (n == 4294967295)
	{
		ft_putchar('4');
		ft_putnbru(294967295);
	}
	else if (n < 10)
	{
		ft_putchar(n + '0');
	}
	else
	{
		ft_putnbru(n / 10);
		ft_putnbru(n % 10);
	}
}
