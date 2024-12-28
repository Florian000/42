/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <florian.granger@student.42.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:49:16 by fgranger          #+#    #+#             */
/*   Updated: 2023/02/05 17:08:51 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MANAGEMENT_H
# define ERROR_MANAGEMENT_H

# define FD_ERROR 2
# define DICT_ERROR "libft/srcs/ft_errors/Dict_error"

void	ft_errors(int errcode);
char	*error_parsing(int errcode);
void	error_print(char *errmsg);

#endif
