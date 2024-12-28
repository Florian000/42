/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:31:01 by fgranger          #+#    #+#             */
/*   Updated: 2022/08/22 14:32:43 by fgranger         ###   ########.fr       */
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

void	ft_putstr(char *str)
{
	int	len;

	len = ft_strlen(str);
	write(1, str, len);
	write(1, "\n", 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] || s2[i]))
		i++;
	return (s1[i] - s2[i]);
}

void	ft_swap(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;

	i = 0;
	while (++i < argc)
	{
		j = i;
		while (++j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) > 0)
				ft_swap(&argv[i], &argv[j]);
		}
	}
	i = 1;
	while (i < argc)
		ft_putstr(argv[i++]);
	return (0);
}
