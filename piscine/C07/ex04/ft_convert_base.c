/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:07:26 by fgranger          #+#    #+#             */
/*   Updated: 2022/09/01 18:55:55 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_space(char c);
int		index_base(char c, char *base);
int		ft_check_base(char *str);
int		ft_atoi_base(char *str, char *base);

int	ft_size(long int nb, int len)
{
	int	size;

	if (nb < 0)
	{
		size = 2;
		nb *= -1;
	}
	else
		size = 1;
	while (nb >= len)
	{
		size++;
		nb /= len;
	}
	return (size);
}

char	*ft_itoa_base(int nb, char *base_to, int len)
{
	char		*str;
	int			size;
	long int	nbr;

	nbr = nb;
	size = ft_size(nbr, len);
	str = NULL;
	str = (char *) malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (NULL);
	if (nbr < 0)
	{
		nbr *= -1;
		str[0] = '-';
	}
	str[size--] = 0;
	while (nbr >= len)
	{
		str[size--] = base_to[nbr % len];
		nbr /= len;
	}
	str[size] = base_to[nbr % len];
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	nb;

	if (!base_from || !base_to)
		return (NULL);
	if (ft_check_base(base_to) <= 1 || ft_check_base(base_from) <= 1)
		return (NULL);
	nb = ft_atoi_base(nbr, base_from);
	return (ft_itoa_base(nb, base_to, ft_check_base(base_to)));
}
