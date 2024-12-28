/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:50:47 by fgranger          #+#    #+#             */
/*   Updated: 2022/12/03 21:28:50 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

int		ft_printf(const char *str, ...);
int		ft_c(va_list args);
int		ft_s(va_list args);
int		ft_p(va_list args);
int		ft_i(va_list args);
int		ft_u(va_list args);
int		ft_x(va_list args);
int		ft_d(va_list args);
int		ft_xucase(va_list args);
int		ft_mod(va_list args);
void	ft_putnbr_base(unsigned long long n, char *base, unsigned int len,
			int *printed);
void	ft_putnbr(int n, int *printed);
int		ft_putchar(char c);

#endif
