/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_util3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 00:36:00 by fmaqdasi          #+#    #+#             */
/*   Updated: 2024/01/11 00:36:47 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	argc_calc(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		i++;
	}
	return (i);
}
