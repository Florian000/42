/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <florian.granger@student.42.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:47:40 by fgranger          #+#    #+#             */
/*   Updated: 2022/12/03 15:24:10 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin_free(char *buffer, char *reading);

#endif
