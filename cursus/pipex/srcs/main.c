/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:24:37 by fgranger          #+#    #+#             */
/*   Updated: 2023/12/29 01:06:38 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	close_fds(int *fd_pipe, int *fd_file)
{
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	close(fd_file[0]);
	close(fd_file[1]);
}

int	openfiles(char *input, char *output, int *fd)
{
	fd[0] = open(input, O_RDONLY);
	if (fd[0] < 0)
		return (EXIT_FAILURE);
	fd[1] = open(output, O_CREAT | O_WRONLY | O_TRUNC, 0000664);
	if (fd[1] < 0)
	{
		close(fd[0]);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	ft_execute(char *cmd, char **env)
{
	char	**args;
	char	*programm;

	args = ft_split(cmd, ' ');
	if (!args)
		malloc_error("ft_execute - malloc");
	if (args[0] == 0)
		programm = ft_strdup("");
	else if (ft_strchr(args[0], '/'))
		programm = ft_strdup(args[0]);
	else
		programm = ft_get_cmd(args[0], env);
	if (!programm)
		return (ft_free_dirs(args), malloc_error("ft_execute - malloc"));
	execve(programm, args, env);
	perror("ft_execute - execution error");
	ft_free_dirs(args);
	free(programm);
	exit(127);
}

void	ft_pipe(char **av, char **env, int *fd_file, int *fd_pipe)
{
	pid_t	pid;

	if (pipe(fd_pipe) == -1)
		return (perror("ft_pipe - pipe error"));
	pid = fork();
	if (pid == -1)
		return (perror("ft_pipe - fork error"));
	if (pid == 0)
	{
		dup2(fd_file[0], STDIN_FILENO);
		dup2(fd_pipe[1], STDOUT_FILENO);
		close_fds(fd_pipe, fd_file);
		ft_execute(av[2], env);
	}
	pid = fork();
	if (pid == -1)
		return (perror("ft_pipe - fork error"));
	if (pid == 0)
	{
		dup2(fd_file[1], STDOUT_FILENO);
		dup2(fd_pipe[0], STDIN_FILENO);
		close_fds(fd_pipe, fd_file);
		ft_execute(av[3], env);
	}
	close_fds(fd_pipe, fd_file);
}

int	main(int ac, char **av, char **env)
{
	int	fd_file[2];
	int	fd_pipe[2];

	if (ac != 5)
		return (ft_putstr_fd(ERROR_ARGS, 2), EXIT_FAILURE);
	if (openfiles(av[1], av[4], fd_file) == EXIT_FAILURE)
		return (perror("main - file"), EXIT_FAILURE);
	ft_pipe(av, env, fd_file, fd_pipe);
	wait(NULL);
	wait(NULL);
	return (EXIT_SUCCESS);
}
