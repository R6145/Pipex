/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:41:46 by fmaqdasi          #+#    #+#             */
/*   Updated: 2024/01/11 16:09:56 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(char **argv, char **envp, int **pipe_fd, int i)
{
	int	fd;

	fd = open(argv[i - 1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		write(2, "\n", 1);
		return (close_pipe(pipe_fd, argc_calc(argv)), free_pipe(pipe_fd),
			exit(3));
	}
	if (dup2(fd, STDIN_FILENO) == -1 || dup2(pipe_fd[0][1], STDOUT_FILENO) ==
		-1)
	{
		ft_putstr_fd("Dup Error\n", 2);
		close(fd);
		return (close_pipe(pipe_fd, argc_calc(argv)), free_pipe(pipe_fd),
			exit(4));
	}
	close_pipe(pipe_fd, argc_calc(argv));
	close(fd);
	if (excute_command(argv, envp, i) == -1)
		return (free_pipe(pipe_fd), exit(127));
}

void	middle_child(char **argv, char **envp, int **pipe_fd, int i)
{
	if (dup2(pipe_fd[i - 3][0], STDIN_FILENO) == -1 || dup2(pipe_fd[i - 2][1],
			STDOUT_FILENO) == -1)
	{
		ft_putstr_fd("Dup Error\n", 2);
		return (close_pipe(pipe_fd, argc_calc(argv)), free_pipe(pipe_fd),
			exit(4));
	}
	close_pipe(pipe_fd, argc_calc(argv));
	if (excute_command(argv, envp, i) == -1)
		return (free_pipe(pipe_fd), exit(127));
}

void	middle(char **argv, char **envp, int **pipe_fd, int i)
{
	pid_t	pid;

	pid = forking(pipe_fd, argc_calc(argv));
	if (pid == 0)
		middle_child(argv, envp, pipe_fd, i);
}

void	parent(char **argv, char **envp, int **pipe_fd, int i)
{
	int	fd;

	fd = open(argv[i + 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		write(2, "\n", 1);
		return (close_pipe(pipe_fd, argc_calc(argv)), free_pipe(pipe_fd),
			exit(3));
	}
	if (dup2(fd, STDOUT_FILENO) == -1 || dup2(pipe_fd[i - 3][0],
		STDIN_FILENO) == -1)
	{
		ft_putstr_fd("Dup Error\n", 2);
		close(fd);
		return (close_pipe(pipe_fd, argc_calc(argv)), free_pipe(pipe_fd),
			exit(4));
	}
	close_pipe(pipe_fd, argc_calc(argv));
	close(fd);
	if (excute_command(argv, envp, i) == -1)
		return (free_pipe(pipe_fd), exit(127));
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		**fd;
	int		i;
	int		exitcode;

	if (argc < 5)
		return (exit(10), 0);
	i = 3;
	fd = fd_create(argc);
	pid = forking(fd, argc);
	if (pid == 0)
		child(argv, envp, fd, i - 1);
	waitpid(0, &exitcode, 0);
	if (exitcode != 0)
	{
		close_pipe(fd, argc);
		return (free_pipe(fd), exit(3), 0);
	}
	while (i < argc - 2)
	{
		middle(argv, envp, fd, i);
		i++;
	}
	parent(argv, envp, fd, argc - 2);
	return (0);
}
