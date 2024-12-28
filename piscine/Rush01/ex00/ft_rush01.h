/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush01.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:34:43 by fgranger          #+#    #+#             */
/*   Updated: 2022/08/21 14:35:09 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RUSH01_H
# define FT_RUSH01_H

void	ft_putchar(char c);
int		ft_strlen(char *str);
void	ft_putstr(char *str);
int		ft_size(char *input);
int		ft_sqrt(int nb);
int		ft_check_input(char *input);
char	*ft_clean_input(char *input, int n, char **grid);
char	**ft_rush01(char **grid, int n);
void	ft_display(char **grid, int n, int *check);
void	ft_backtrack(char **grid, int pos, int n, int *check);
void	ft_free(char **grid);
int		ft_check_tower(char **grid, int pos, int n);
int		ft_check_doubles(char **grid, int pos, int n);
void	ft_count_row_down(char **grid, int pos, int n, char *count);
void	ft_count_row_up(char **grid, int pos, int n, char *count);
void	ft_count_col_up(char **grid, int pos, int n, char *count);
void	ft_count_col_down(char **grid, int pos, int n, char *count);
int		ft_check_counts(char **grid, int pos, int n);
int		ft_check_const(char **grid, int pos, int n);

#endif
