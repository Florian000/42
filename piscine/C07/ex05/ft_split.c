/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:08:21 by fgranger          #+#    #+#             */
/*   Updated: 2022/08/30 10:46:53 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_charset(char *charset, char c)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str, int index, char *charset)
{
	int	len;

	len = index;
	while (str[len] && !(ft_charset(charset, str[len])))
		len++;
	return (len);
}

char	*ft_strdup(char *src, int index, char *charset)
{
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	str = (char *) malloc(sizeof(char) * ft_strlen(src, index, charset) + 1);
	if (str == NULL)
		return (NULL);
	while (src[index] && !ft_charset(charset, src[index]))
		str[i++] = src[index++];
	str[i] = 0;
	return (str);
}

int	ft_size(char *str, char *charset)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (ft_charset(charset, str[i]))
		i++;
	while (str[i])
	{
		while (!ft_charset(charset, str[i]) && str[i])
			i++;
		while (ft_charset(charset, str[i]) && str[i])
			i++;
		size++;
	}
	return (size);
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	int		i;
	int		j;

	strs = NULL;
	strs = (char **) malloc(sizeof(char *) * ft_size(str, charset) + 1);
	if (strs == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (ft_charset(charset, str[j]) && str[j])
		j++;
	while (i < ft_size(str, charset))
	{
		strs[i] = ft_strdup(str, j, charset);
		while (!ft_charset(charset, str[j]) && str[j])
			j++;
		while (ft_charset(charset, str[j]) && str[j])
			j++;
		i++;
	}
	strs[i] = 0;
	return (strs);
}
