/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:01:01 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/12/24 18:04:16 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	cho(char c, va_list *args)
{
	if (c == 'c')
		return (charp(va_arg(*args, int)));
	else if (c == 's')
		return (strp(va_arg(*args, char *)));
	else if (c == 'p')
		return (pontp(va_arg(*args, unsigned long long)));
	else if (c == 'd')
		return (dec(va_arg(*args, unsigned long long)));
	else if (c == 'i')
		return (dec(va_arg(*args, unsigned long long)));
	else if (c == 'u')
		return (dec2(va_arg(*args, unsigned long long)));
	else if (c == 'x')
		return (hexp(va_arg(*args, unsigned long long)));
	else if (c == 'X')
		return (hexp2(va_arg(*args, unsigned long long)));
	else if (c == '%')
		return (charp('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		cont;

	i = 0;
	cont = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			cont = cont + cho(str[i], &args);
		}
		else
		{
			cont++;
			ft_putchar(str[i]);
		}
		i++;
	}
	va_end(args);
	return (cont);
}
