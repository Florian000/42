/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <florian.granger@student.42.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:47:50 by fgranger          #+#    #+#             */
/*   Updated: 2022/12/04 10:43:33 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		len_s1;
	int		len_s2;

	if (!s1 || !s2)
		return (NULL);
	new = NULL;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new = (char *) malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!new)
		return (NULL);
	ft_memcpy(new, s1, len_s1);
	ft_memcpy(new + len_s1, s2, len_s2);
	return (new);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	((unsigned char *)dest)[i] = '\0';
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (c == 0)
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_strjoin_free(char *buffer, char *reading)
{
	char	*tmp;

	tmp = ft_strjoin(buffer, reading);
	free(buffer);
	return (tmp);
}
