/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 12:56:31 by fgranger          #+#    #+#             */
/*   Updated: 2022/08/23 12:58:39 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*str;
	int		len_c;
	int		i;

	i = 0;
	len_c = ft_strlen(src);
	str = NULL;
	str = (char *) malloc(sizeof(char) * len_c + 1);
	if (str == NULL)
		return (NULL);
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

t_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*strs;

	i = 0;
	strs = NULL;
	strs = malloc(sizeof(t_stock_str) * (ac + 1));
	if (strs == NULL)
		return (NULL);
	while (i < ac)
	{
		strs[i].size = ft_strlen(av[i]);
		strs[i].str = av[i];
		strs[i].copy = ft_strdup(av[i]);
		i++;
	}
	strs[i].str = 0;
	return (strs);
}
