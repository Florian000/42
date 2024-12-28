/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 12:01:34 by fgranger          #+#    #+#             */
/*   Updated: 2022/08/24 17:56:39 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
		i++;
	while (--i >= 0)
	{
		j = 0;
		while (++j <= i)
			if (cmp(tab[j - 1], tab[j]) > 0)
				ft_swap(&tab[j - 1], &tab[j]);
	}
}
