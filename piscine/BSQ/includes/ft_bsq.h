/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:57:40 by fgranger          #+#    #+#             */
/*   Updated: 2022/08/31 00:14:24 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H

typedef struct s_map	t_map;
struct s_map
{
	int		lines;
	int		len;
	char	empty;
	char	obs;
	char	full;
	int		*map;
};

int		ft_bsq(t_map *params);
void	ft_map(char *file, int fd);
char	*ft_open_map(char *file, int fd);
int		ft_read_map(int fd, char **map);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
char	*ft_strcat(char *dest, char *src);
int		ft_atoi(char *str, int i);
char	ft_is_printable(char c);
void	ft_free_str(char *str);
void	ft_free_params(t_map *params);
int		ft_check_map(char *map, t_map *params);
int		ft_check_lines(char *map, int i, t_map *params);
int		ft_get_params(char *map, t_map *params);
int		ft_check_char(t_map *params);
char	*ft_convert_map(t_map *params);
void	ft_print_map(t_map *params, int max);
int		*ft_clean(char *str, t_map *params);
void	new_max(int size, int *max, int i, int max_val);

#endif
