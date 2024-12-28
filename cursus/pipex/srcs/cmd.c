/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:44:50 by fgranger          #+#    #+#             */
/*   Updated: 2023/12/29 00:23:03 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	malloc_error(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	ft_free_dirs(char **dirs)
{
	int	i;

	i = 0;
	while (dirs[i])
		free(dirs[i++]);
	free(dirs);
}

char	*ft_get_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}

char	*ft_get_cmd(char *cmd, char **env)
{
	int		i;
	char	*path;
	char	**dirs;
	char	*programm;
	char	*tmp;

	i = -1;
	path = ft_get_path(env);
	dirs = ft_split(path, ':');
	if (!dirs)
		return (malloc_error("ft_get_cmd - malloc error"), NULL);
	while (dirs[++i])
	{
		tmp = ft_strjoin(dirs[i], "/");
		if (!tmp)
			return (malloc_error("ft_get_cmd - malloc error"), NULL);
		programm = ft_strjoin(tmp, cmd);
		if (!programm)
			return (malloc_error("ft_get_cmd - malloc error"), free(tmp), NULL);
		free(tmp);
		if (!access(programm, F_OK | X_OK))
			return (ft_free_dirs(dirs), programm);
		free(programm);
	}
	return (ft_free_dirs(dirs), ft_strdup(cmd));
}
