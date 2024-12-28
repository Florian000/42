/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <florian.granger@student.42.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:51:54 by fgranger          #+#    #+#             */
/*   Updated: 2022/12/03 15:22:13 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# define OPEN_MAX 65534
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin_free(char *buffer, char *reading);

#endif
