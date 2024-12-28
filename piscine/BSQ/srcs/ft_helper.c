/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:43:17 by fgranger          #+#    #+#             */
/*   Updated: 2022/08/31 00:22:46 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str, int i)
{
	int	j;
	int	nb;

	j = 0;
	nb = 0;
	while (j <= i)
		nb = nb * 10 + str[j++] - '0';
	if (j != i + 1)
		return (0);
	return (nb);
}

char	ft_is_printable(char c)
{
	if (c > 32 && c < 127)
		return (c);
	return ('\0');
}

void	new_max(int size, int *max, int i, int max_val)
{
	if (size > max_val)
		*max = i;
}
