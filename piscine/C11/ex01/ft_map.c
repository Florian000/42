/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:03:31 by fgranger          #+#    #+#             */
/*   Updated: 2022/08/24 17:59:10 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*new_tab;
	int	i;

	new_tab = NULL;
	new_tab = (int *) malloc(sizeof(int) * length);
	if (new_tab == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		new_tab[i] = f(tab[i]);
		i++;
	}
	return (new_tab);
}
