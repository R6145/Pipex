/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_util3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 00:36:00 by fmaqdasi          #+#    #+#             */
/*   Updated: 2024/01/13 23:32:43 by fmaqdasi         ###   ########.fr       */
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

void	here_doc(char **argv)
{
	char	*input;
	int		flag;
	int		fd;

	flag = 0;
	fd = open("here_doc", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		write(2, "\n", 1);
		return (exit(1));
	}
	input = get_next_line(0);
	while (input != NULL && flag == 0)
	{
		if (ft_strncmp(argv[2], input, ft_strlen(argv[2])) == 0)
			flag = 1;
		if (flag != 1)
			ft_putstr_fd(input, fd);
		free(input);
		if (flag != 1)
			input = get_next_line(0);
	}
	close(fd);
}

void	del_here_doc(char **argv)
{
	if ((ft_strncmp(argv[1], "here_doc", 9) == 0))
	{
		wait(NULL);
		unlink("here_doc");
	}
}
