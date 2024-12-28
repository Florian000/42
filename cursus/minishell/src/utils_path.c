/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:39:25 by yuewang           #+#    #+#             */
/*   Updated: 2024/04/21 20:49:21 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*find_var_from_envp(t_lst_env *env, char *var_name)
{
	char	*varible;

	while (env)
	{
		if (ft_strcmp(env->key, var_name) == 0)
		{
			return (env->value);
		}
		env = env->next;
	}
	return (NULL);
}

t_lst_env	*find_path_from_envp(t_lst_env *env_list, const char *var_name)
{
	while (env_list)
	{
		if (ft_strncmp(env_list->key, var_name, ft_strlen(var_name)) == 0)
			return (env_list);
		env_list = env_list->next;
	}
	return (NULL);
}
