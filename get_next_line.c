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

#include "get_next_line.h"

int		check_in_store(char **line, char **storage)
{
	if ((*line = find_new_piece(storage)))
		return (1);
	if (ft_strchr(*storage, '\n'))
		return (-1);
	return (0);
}

char	*ft_strdup(char const *s)
{
	char	*res;
	size_t	i;

	if (!s)
		i = 0;
	else
		i = ft_strlen(s);
	res = (char*)malloc(sizeof(char) * i + 1);
	if (res == NULL)
		return (NULL);
	ft_memcpy(res, s, i);
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin_gnl(char *s1, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		i = 0;
	else
		i = ft_strlen(s1);
	j = ft_strlen(s2);
	res = (char*)malloc(sizeof(char) * (j + i) + 1);
	if (res == NULL)
		return (NULL);
	if (s1)
	{
		ft_memcpy(res, s1, i);
		free(s1);
	}
	ft_memcpy(res + i, s2, j);
	res[j + i] = '\0';
	return (res);
}

char	*find_new_piece(char **storage)
{
	char			*new_piece;
	char			*n_ptr;
	char			*tmp;

	if ((n_ptr = ft_strchr(*storage, '\n')))
	{
		new_piece = (char*)malloc(n_ptr - *storage + 1);
		if (new_piece == NULL)
			return (NULL);
		ft_strlcpy(new_piece, *storage, n_ptr - *storage + 1);
		if (!(tmp = ft_strdup(ft_strchr(*storage, '\n') + 1)))
			return (NULL);
		free(*storage);
		*storage = tmp;
		return (new_piece);
	}
	else
		return (NULL);
}

int		get_next_line(int fd, char **line)
{
	char		get_red[BUFFER_SIZE + 1];
	int			tmp;
	static char	*storage = NULL;

	if (BUFFER_SIZE <= 0 || fd < 0 || !line)
		return (-1);
	if (storage)
		if ((tmp = check_in_store(line, &storage)))
			return (tmp);
	ft_bzero(get_red, BUFFER_SIZE + 1);
	while ((tmp = read(fd, get_red, BUFFER_SIZE)) > 0)
	{
		if (!(storage = ft_strjoin_gnl(storage, get_red)))
			return (-1);
		if ((*line = find_new_piece(&storage)))
			return (1);
		ft_bzero(get_red, BUFFER_SIZE + 1);
	}
	if (tmp < 0)
		return (-1);
	if (!(*line = ft_strdup(storage)))
		return (-1);
	free(storage);
	return (0);
}
