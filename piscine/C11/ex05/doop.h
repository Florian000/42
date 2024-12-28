/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 13:27:29 by fgranger          #+#    #+#             */
/*   Updated: 2022/08/30 13:21:08 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOP_H
# define DOOP_H

void	ft_putchar(char c);
void	ft_putnbr(long int nb);
void	ft_putstr(char *str);
int		ft_add(long int a, long int b);
int		ft_sub(long int a, long int b);
int		ft_div(long int a, long int b);
int		ft_mul(long int a, long int b);
int		ft_mod(long int a, long int b);
int		ft_err(long int a, long int b);
int		select_ft(char *str);
void	ft_doop(long int a, char *ops, long int b);
int		ft_atoi(char *nb);

#endif
