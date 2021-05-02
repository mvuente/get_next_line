/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <mvuente@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 10:28:39 by mvuente           #+#    #+#             */
/*   Updated: 2020/05/27 11:51:17 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

void		*ft_memcpy(void	*dest, const void *src, size_t n);
int			check_in_store(char **line, char **storage);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlen(const char *x);
void		ft_bzero(void *c, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
char		*ft_strdup(char const *s);
char		*ft_strjoin_gnl(char *s1, char const *s2);
char		*find_new_piece(char **storage);
int			get_next_line(int fd, char **line);

#endif
