/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:24:42 by fmaqdasi          #+#    #+#             */
/*   Updated: 2024/01/03 16:23:51 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_split(char **var)
{
	int	i;

	i = 0;
	while (var[i] != NULL)
	{
		free(var[i]);
		i++;
	}
	free(var);
}

char	*find_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

char	*create_command(char *command, char *path)
{
	char	*full_command;
	char	*full_command2;
	char	**args;
	int		i;

	args = ft_split(path, ':');
	if (!args)
		return (NULL);
	i = 0;
	while (args[i] != NULL)
	{
		full_command = ft_strjoin(args[i], "/");
		if (!full_command)
			return (free_split(args), NULL);
		full_command2 = full_command;
		full_command = ft_strjoin(full_command, command);
		if (!full_command)
			return (free(full_command2), free_split(args), NULL);
		free(full_command2);
		if (access(full_command, X_OK) == 0)
			return (free_split(args), full_command);
		free(full_command);
		i++;
	}
	return (ft_printf("Error: Unknown Command\n"), free_split(args), NULL);
}

void	excute_command(char **argv, char **envp, int x)
{
	char	**command;
	char	*command1;

	if (x == 1)
		command = ft_split(argv[2], ' ');
	else
		command = ft_split(argv[3], ' ');
	command1 = create_command(command[0], find_path(envp));
	if (command1 == NULL)
		exit(127);
	if (execve(command1, command, envp) == -1)
	{
		ft_printf("Error: %s\n", strerror(errno));
		free_split(command);
		free(command1);
	}
}
