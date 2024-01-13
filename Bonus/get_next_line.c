/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:51:28 by fmaqdasi          #+#    #+#             */
/*   Updated: 2024/01/13 22:42:30 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*freest(char *buff, char *st, int x)
{
	char	*temp;

	if (x == 1)
	{
		temp = ft_strjoin(buff, st);
		free(buff);
		return (temp);
	}
	else if (x == 2 && buff != NULL)
	{
		free(buff);
		return (NULL);
	}
	return (NULL);
}

char	*readline(int fd, char *buff)
{
	char	*st;
	int		x;

	x = 1;
	if (buff == NULL)
		buff = ft_calloc(1, 1);
	st = (char *)ft_calloc((long)BUFFER_SIZE + 1, 1);
	while (x > 0)
	{
		x = read(fd, st, BUFFER_SIZE);
		if (x < 0)
		{
			free(st);
			free(buff);
			return (NULL);
		}
		st[x] = '\0';
		if (ft_strchr(st, '\n') != NULL)
			x = -1;
		buff = freest(buff, st, 1);
	}
	free(st);
	return (buff);
}

char	*writeline(char *buff)
{
	int		i;
	char	*st;

	i = 0;
	st = (char *)ft_calloc(ft_strlen(buff) + 1, 1);
	while (buff[i] != '\n' && buff[i] != '\0')
	{
		st[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
		st[i] = buff[i];
	return (st);
}

char	*bufferup(char *buff)
{
	char	*st;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	if (buff[i] == '\n')
		i++;
	st = (char *)ft_calloc(ft_strlen(buff) - i + 2, 1);
	while (buff[i + j] != '\0')
	{
		st[j] = buff[i + j];
		j++;
	}
	if (st != NULL && ft_strlen(st) == 0)
	{
		free(st);
		free(buff);
		return (NULL);
	}
	free(buff);
	return (st);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		buff = freest(buff, "", 2);
		return (NULL);
	}
	buff = readline(fd, buff);
	line = writeline(buff);
	buff = bufferup(buff);
	if (line[0] == '\0')
	{
		free(line);
		buff = freest(buff, "", 2);
		return (NULL);
	}
	return (line);
}
