/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:38:58 by fgranger          #+#    #+#             */
/*   Updated: 2022/08/30 13:43:48 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	incr;
	int	decr;

	i = 0;
	incr = 1;
	decr = 1;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			incr = 0;
		i++;
	}
	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			decr = 0;
		i++;
	}
	if (decr == 0 && incr == 0)
		return (0);
	return (1);
}
