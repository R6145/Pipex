/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:41:46 by fmaqdasi          #+#    #+#             */
/*   Updated: 2024/01/04 18:39:22 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(char **argv, char **envp, int *pipe_fd)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error: %s\n", strerror(errno));
		return (close(pipe_fd[1]), close(pipe_fd[0]), exit(3));
	}
	if (dup2(fd, STDIN_FILENO) == -1 || dup2(pipe_fd[1], STDOUT_FILENO) == -1)
	{
		ft_printf("Dup Error\n");
		close(fd);
		return (close(pipe_fd[1]), close(pipe_fd[0]), exit(4));
	}
	close(pipe_fd[0]);
	close(fd);
	close(pipe_fd[1]);
	excute_command(argv, envp, 1);
}

void	parent(char **argv, char **envp, int *pipe_fd)
{
	int	fd;

	waitpid(0, NULL, 0);
	fd = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (fd == -1)
	{
		ft_printf("Error: %s\n", strerror(errno));
		return (close(pipe_fd[1]), close(pipe_fd[0]), exit(3));
	}
	if (dup2(fd, STDOUT_FILENO) == -1 || dup2(pipe_fd[0], STDIN_FILENO) == -1)
	{
		ft_printf("Dup Error\n");
		close(fd);
		return (close(pipe_fd[1]), close(pipe_fd[0]), exit(4));
	}
	close(pipe_fd[0]);
	close(fd);
	close(pipe_fd[1]);
	excute_command(argv, envp, 2);
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (argc != 5)
		return (exit(10), 0);
	if (pipe(fd) == -1)
	{
		ft_printf("Pipe failed\n");
		return (exit(5), 0);
	}
	pid = fork();
	if (pid == -1)
	{
		ft_printf("Fork failed\n");
		close(fd[0]);
		close(fd[1]);
		return (exit(5), 0);
	}
	if (pid == 0)
		child(argv, envp, fd);
	else
		parent(argv, envp, fd);
	return (0);
}
