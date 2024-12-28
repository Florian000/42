/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 12:03:08 by fgranger          #+#    #+#             */
/*   Updated: 2022/08/15 12:07:40 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 1)
		return (!nb);
	else
		return (nb * ft_recursive_factorial(nb - 1));
}
