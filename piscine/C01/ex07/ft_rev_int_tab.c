/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:54:47 by fgranger          #+#    #+#             */
/*   Updated: 2022/08/10 18:50:55 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size)
	{
		tmp = tab[i];
		tab[i] = tab[size -1];
		tab[size -1] = tmp;
		i++;
		size--;
	}
}
