/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:15:32 by fgranger          #+#    #+#             */
/*   Updated: 2022/08/11 21:16:00 by fgranger         ###   ########.fr       */
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

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	len_d;

	i = 0;
	len_d = ft_strlen(dest);
	while (src[i] && i < nb)
	{
		dest[len_d + i] = src[i];
		i++;
	}
	dest[len_d + i] = 0;
	return (dest);
}
