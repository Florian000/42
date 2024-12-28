/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 06:39:08 by yuewang           #+#    #+#             */
/*   Updated: 2024/04/21 17:31:00 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	free_file_list(t_lst_file *head)
{
	t_lst_file	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp->name);
		if (tmp->type == 0 && tmp->mode == 1)
			unlink(".here_doc");
		free(tmp);
	}
}

void	free_process(t_process *process)
{
	if (process)
	{
		if (process->command)
			free(process->command);
		if (process->pathname)
			free(process->pathname);
		if (process->args)
			ft_freetab(process->args);
		if (process->file)
			free_file_list(process->file);
		free(process);
	}
}

void	cleanup_resources(t_prompt *prompt)
{
	int	i;

	i = 0;
	while (i < prompt->process_count)
	{
		if (prompt->process[i])
		{
			ft_freetab(prompt->process[i]->args);
			free(prompt->process[i]->command);
			free(prompt->process[i]);
		}
		i++;
	}
	free(prompt->process);
	if (prompt->backup_fd[0] != 0)
		close(prompt->backup_fd[0]);
	if (prompt->backup_fd[1] != 1)
		close(prompt->backup_fd[1]);
	ft_free_env(prompt->shell->env);
}

void	cleanup_readline(void)
{
	clear_history();
	rl_clear_history();
	rl_cleanup_after_signal();
	rl_deprep_terminal();
}

void	clean(t_shell *shell)
{
	if (shell)
	{
		if (shell->env)
			ft_free_env(shell->env);
		cleanup_readline();
		free(shell);
	}
}
