/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:06:14 by fgranger          #+#    #+#             */
/*   Updated: 2022/08/19 14:06:15 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlencharset(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strlen(char **str, int size, char *sep)
{
	int	j;
	int	i;
	int	len;
	int	charset;

	len = 0;
	i = 0;
	charset = ft_strlencharset(sep);
	while (i < size)
	{
		j = 0;
		while (str[i][j])
		{
			j++;
			len++;
		}
		i++;
		len += charset;
	}
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*join;
	int		src;
	int		dest;
	int		n;

	join = NULL;
	join = (char *) malloc(sizeof(char) * ft_strlen(strs, size, sep) + 1);
	if (join == NULL)
		return (NULL);
	dest = 0;
	n = 0;
	while (n < size)
	{
		src = 0;
		while (strs[n][src])
			join[dest++] = strs[n][src++];
		n++;
		src = 0;
		while (sep[src] && n < size)
			join[dest++] = sep[src++];
	}
	join[dest] = 0;
	return (join);
}
