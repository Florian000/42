/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:22:37 by yuewang           #+#    #+#             */
/*   Updated: 2024/04/21 18:00:20 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include "../src/libft/inc/libft.h"
# include <stdbool.h>

enum	e_export_status
{
	UNVALID,
	EMPTY,
	VALID,
};

typedef struct s_prompt				t_prompt;
typedef struct s_shell				t_shell;
typedef struct s_lst_file			t_lst_file;
typedef struct s_lst_env			t_lst_env;

typedef struct s_process
{
	int					index;
	char				*command;
	char				*pathname;
	int					argc;
	char				**args;
	int					*delimiters;
	int					fd[2];
	int					pid;
	int					return_status;
	t_lst_file			*file;
	t_prompt			*prompt;
	t_shell				*shell;
}						t_process;

typedef struct s_prompt
{
	t_list				*token;
	t_process			**process;
	int					process_count;
	int					last_exit;
	int					backup_fd[2];
	int					last_pipe_fd;
	t_shell				*shell;
}						t_prompt;

typedef struct s_shell
{
	t_lst_env			*env;
	t_prompt			*prompt;
	bool				exit;
	int					exit_status;
	int					pid;
	int					error;
	int					fd[2];
}						t_shell;

typedef struct s_lst_file
{
	int					type;
	int					mode;
	char				*name;
	struct s_lst_file	*next;
}						t_lst_file;

typedef struct s_lst_env
{
	char				*key;
	char				*value;
	bool				export_only;
	struct s_lst_env	*next;
}						t_lst_env;

#endif
