/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:10:18 by fgranger          #+#    #+#             */
/*   Updated: 2022/08/31 21:08:17 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "ft_bsq.h"

void	ft_map_error(char *map, t_map *params)
{
	write(2, "map error\n", 10);
	if (map)
		ft_free_str(map);
	free(params);
}

void	ft_map(char *file, int fd)
{
	char	*map;
	t_map	*params;
	int		max;

	params = (t_map *) malloc(sizeof(t_map));
	if (!params)
		return ;
	map = ft_open_map(file, fd);
	if (!map)
	{
		ft_map_error(map, params);
		return ;
	}
	if (!ft_check_map(map, params))
	{
		ft_map_error(map, params);
		return ;
	}
	params->map = ft_clean(map, params);
	ft_free_str(map);
	max = ft_bsq(params);
	ft_print_map(params, max);
	ft_free_params(params);
}

char	*ft_open_map(char *file, int fd)
{
	char	*map;
	int		fr;

	if (fd > 0)
		fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map = (char *) malloc(sizeof(char));
	if (map == NULL)
		return (NULL);
	*map = 0;
	fr = ft_read_map(fd, &map);
	close(fd);
	if (!fr)
		return (NULL);
	return (map);
}

int	ft_read_map(int fd, char **map)
{
	char	buf[100000];
	char	*tmp;
	int		len;
	int		off;

	off = 0;
	len = 1;
	while (len)
	{
		len = read(fd, buf, 99999);
		if (len < 0)
			return (0);
		tmp = (char *) malloc(sizeof(char) * (len + off + 1));
		if (tmp == NULL)
			return (0);
		tmp[0] = 0;
		buf[len] = 0;
		tmp = ft_strcat(tmp, *map);
		ft_strcat(tmp, buf);
		free(*map);
		*map = tmp;
		off += len;
	}
	return (1);
}
