/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathname.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:39:25 by yuewang           #+#    #+#             */
/*   Updated: 2024/04/21 20:08:50 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*get_first_word(char *str)
{
	int		i;
	int		len;
	char	*first_word;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	len = i;
	first_word = malloc(len + 1);
	if (!first_word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		first_word[i] = str[i];
		i++;
	}
	first_word[i] = '\0';
	return (first_word);
}

char	*create_full_path(char *dir, char *cmd)
{
	char	*tmp;
	char	*full_path;

	tmp = ft_strjoin(dir, "/");
	if (!tmp)
		return (NULL);
	full_path = ft_strjoin(tmp, cmd);
	free(tmp);
	return (full_path);
}

int	check_path_errors(char *command, t_process *process)
{	
	struct stat	file_stat;

	if (!command)
		return (EXIT_FAILURE);
	if (ft_strncmp(command, "/", 1) == 0 || ft_strncmp(command, "./", 2) == 0)
	{
		if (lstat(command, &file_stat) == 0)
		{
			if (S_ISDIR(file_stat.st_mode))
				exec_error2(process, "Is a directory\n", 126, process->pid);
			if (file_stat.st_mode & S_IXUSR)
				return (EXIT_SUCCESS);
			if (access(command, R_OK) == 0)
				exec_error2(process, "Is a file\n", 126, process->pid);
			else
				exec_error2(process, "Permission denied\n", 126,
					process->pid);
		}
		else
			exec_error2(process, "No such file or directory\n", 127,
				process->pid);
	}
	return (EXIT_SUCCESS);
}

char	*check_path_comb(char **path, char *command)
{
	int		i;
	char	*pathname;

	i = 0;
	while (path[i])
	{
		pathname = create_full_path(path[i], command);
		if (pathname && access(pathname, F_OK | X_OK) == 0)
			return (pathname);
		free(pathname);
		i++;
	}	
	return (NULL);
}

char	*get_pathname(t_lst_env *env, char *command, t_process *process)
{
	char		*pathname;
	t_lst_env	*path_env;
	char		**path;
	char		*found_pathname;

	if (check_path_errors(command, process) == EXIT_FAILURE)
		return (NULL);
	if (access(command, F_OK | X_OK) == 0)
		return (command);
	path_env = find_path_from_envp(env, "PATH");
	if (!path_env || !path_env->value)
		return (NULL);
	path = ft_split(path_env->value, ':');
	if (!path)
		return (NULL);
	found_pathname = check_path_comb(path, command);
	ft_freetab(path);
	if (found_pathname)
		return (found_pathname);
	else
		return (NULL);
}
