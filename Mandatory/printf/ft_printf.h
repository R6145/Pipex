/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 10:59:09 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/12/24 18:04:57 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_putstr(char *s);
size_t	ft_strlen2(const char *ch);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putnbru(unsigned long int n);

int		ft_printf(const char *str, ...);
int		charp(char x);
int		strp(char *str);
int		pontp(unsigned long long x);
int		dec(int x);
int		dec2(unsigned int x);
int		hexp(unsigned int x);
int		hexp2(unsigned int x);

#endif