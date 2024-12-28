/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:45:08 by fgranger          #+#    #+#             */
/*   Updated: 2023/12/29 00:22:30 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/includes/libft.h"
# include <wait.h>

# define ERROR_ARGS "Wrong number of arguments \n\
Usage : ./pipex <file1> <cmd1> <cmd2> <file2>\n"

char	*ft_get_cmd(char *cmd, char **env);
void	ft_free_dirs(char **dirs);
void	malloc_error(char *msg);
#endif
