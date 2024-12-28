/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 06:39:08 by yuewang           #+#    #+#             */
/*   Updated: 2024/04/21 21:54:02 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	free_prompt(t_prompt *prompt)
{
	int	i;

	if (!prompt)
		return ;
	if (prompt->token)
		ft_freelst(prompt->token);
	i = 0;
	while (i < prompt->process_count)
	{
		if (prompt->process[i])
			free_process(prompt->process[i]);
		i++;
	}
	free(prompt->process);
	free(prompt);
}

void	ft_free_env(t_lst_env *env)
{
	t_lst_env	*temp;

	while (env)
	{
		temp = env;
		env = env->next;
		free(temp->key);
		free(temp->value);
		free(temp);
	}
}
