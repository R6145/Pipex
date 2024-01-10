/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:41:46 by fmaqdasi          #+#    #+#             */
/*   Updated: 2024/01/10 18:10:39 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(char **argv, char **envp, int **pipe_fd, int i)
{
	int	fd;

	fd = open(argv[i - 1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error: %s\n", strerror(errno));
		return (close_pipe(pipe_fd, argc_calc(argv)), exit(3));
	}
	if (dup2(fd, STDIN_FILENO) == -1 || dup2(pipe_fd[0][1], STDOUT_FILENO) ==
		-1)
	{
		ft_printf("Dup Error\n");
		close(fd);
		return (close_pipe(pipe_fd, argc_calc(argv)), exit(4));
	}
	close_pipe(pipe_fd, argc_calc(argv));
	close(fd);
	excute_command(argv, envp, i);
}

void	middle_child(char **argv, char **envp, int **pipe_fd, int i)
{
	if (dup2(pipe_fd[0][0], STDIN_FILENO) == -1 || dup2(pipe_fd[0][1],
			STDOUT_FILENO) == -1)
	{
		ft_printf("Dup Error\n");
		return (close_pipe(pipe_fd, argc_calc(argv)), exit(4));
	}
	close_pipe(pipe_fd, argc_calc(argv));
	excute_command(argv, envp, i);
}

// void	middle(char **argv, char **envp, int i)
// {
// 	pid_t	pid;
// 	int		fd[2];

// 	pid = fork_pipe(fd);
// 	if (pid == 0 && i == 2)
// 		child(argv, envp, fd, i - 1);
// 	if (pid == 0)
// 		middle_child(argv, envp, fd, i);
// 	waitpid(0, NULL, 0);
// }

void	parent(char **argv, char **envp, int **pipe_fd, int i)
{
	int	fd;

	fd = open(argv[i + 1], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (fd == -1)
	{
		ft_printf("Error: %s\n", strerror(errno));
		return (close_pipe(pipe_fd, argc_calc(argv)), exit(3));
	}
	if (dup2(fd, STDOUT_FILENO) == -1 || dup2(pipe_fd[0][0], STDIN_FILENO) ==
		-1)
	{
		ft_printf("Dup Error\n");
		close(fd);
		return (close_pipe(pipe_fd, argc_calc(argv)), exit(4));
	}
	close_pipe(pipe_fd, argc_calc(argv));
	close(fd);
	excute_command(argv, envp, i);
}

pid_t	forking(int **fd,int argc)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		ft_printf("Fork failed\n");
		return (close_pipe(fd, argc), exit(5), 0);
	}
	return (pid);
}

int	**fd_create(int argc)
{
	int	**x;
	int	i;

	i = 0;
	x = malloc(sizeof(int *) * (argc - 3));
	while (i < argc - 4)
	{
		x[i] = malloc(sizeof(int) * (2));
		i++;
	}
	x[i] = NULL;
	i = 0;
	while (i < argc - 4)
	{
		if (pipe(x[i]) == -1)
		{
			ft_printf("Pipe failed\n");
			return (exit(5), NULL);
		}
		i++;
	}
	return (x);
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		**fd;
	int		i;
	int		exit_code;

	if (argc < 5)
		return (exit(10), 0);
	i = 3;
	fd = fd_create(argc);
	// pid = fork_pipe(fd);
	pid = forking(fd,argc);
	if (pid == 0)
		child(argv, envp, fd, i - 1);
	waitpid(0, &exit_code, 0);
	while (i < argc - 2)
	{
		// printf("here\n");
		// pid = fork_pipe(fd);
		// middle(argv, envp, i);
		i++;
	}
	parent(argv, envp, fd, argc - 2);
	return (exit_code);
}

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

void	close_pipe(int **fd, int argc)
{
	int i;

	i = 0;
	while (i < argc - 4)
	{
		close(fd[i][0]);
		close(fd[i][1]);
		i++;
	}
}