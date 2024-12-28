/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <florian.granger@student.42.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:34:52 by fgranger          #+#    #+#             */
/*   Updated: 2023/02/05 17:13:06 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_errors(int errcode)
{
	char	*errmsg;

	if (errcode == 0)
	{
		ft_putstr_fd("The 0 error code cannot be used", FD_ERROR);
		ft_putchar_fd('\n', FD_ERROR);
		return ;
	}
	errmsg = error_parsing(errcode);
	if (!errmsg)
	{
		ft_putstr_fd("The following error was not found : ", FD_ERROR);
		ft_putnbr_fd(errcode, FD_ERROR);
		ft_putchar_fd('\n', FD_ERROR);
		return ;
	}
	error_print(errmsg);
	free(errmsg);
}

char	*error_parsing(int errcode)
{
	char	*line;
	int		fd;
	char	*tmp;

	fd = open(DICT_ERROR, O_RDONLY);
	if (fd < 0)
		return ("0 : Impossible to open Dict_error");
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		if (ft_atoi(tmp) == errcode)
			line = ft_strdup(tmp);
		free(tmp);
	}
	close(fd);
	if (line)
		return (line);
	return (NULL);
}

void	error_print(char *errmsg)
{
	ft_putstr_fd("Error code ", FD_ERROR);
	ft_putendl_fd(errmsg, FD_ERROR);
}
