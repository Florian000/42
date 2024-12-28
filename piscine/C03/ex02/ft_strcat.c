/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:14:03 by fgranger          #+#    #+#             */
/*   Updated: 2022/08/11 22:26:40 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	len_d;

	i = 0;
	len_d = ft_strlen(dest);
	while (src[i])
	{
		dest[len_d + i] = src[i];
		i++;
	}
	dest[len_d + i] = 0;
	return (dest);
}
