/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:16:56 by fgranger          #+#    #+#             */
/*   Updated: 2022/08/11 21:17:16 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;

	len = 0;
	i = 0;
	while (dest[len] && len < size)
		len++;
	while (src[i] && size && len + i < size -1)
	{
		dest[len + i] = src[i];
		i++;
	}
	if (len < size)
		dest[len + i] = 0;
	i = 0;
	while (src[i])
		i++;
	return (len + i);
}
