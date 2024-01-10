/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:33:04 by fmaqdasi          #+#    #+#             */
/*   Updated: 2024/01/11 00:32:17 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

void	free_split(char **var);
char	*find_path(char **envp);
char	*create_command(char *command, char *path);
void	child(char **argv, char **envp, int **pipe_fd, int i);
void	parent(char **argv, char **envp, int **pipe_fd, int i);
int		excute_command(char **argv, char **envp, int x);
pid_t	forking(int **fd, int argc);
void	middle_child(char **argv, char **envp, int **pipe_fd, int i);
void	close_pipe(int **fd, int argc);
void	middle(char **argv, char **envp, int **pipe_fd, int i);
int		**fd_create(int argc);
int		argc_calc(char **argv);
void	free_pipe(int **fd);
void	piping(int **x, int argc);

#endif