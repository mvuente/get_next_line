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

size_t	ft_strlen(const char *x)
{
	size_t i;

	i = 0;
	while (x[i] != '\0')
		i++;
	return (i);
}

void	ft_bzero(void *c, size_t n)
{
	unsigned char	*res;
	int				i;

	res = (unsigned char*)c;
	i = 0;
	while (n--)
	{
		res[i] = '\0';
		i++;
	}
}

char	*ft_strchr(const char *s, int c)
{
	char	*res;
	char	smb;

	smb = (char)c;
	res = (char*)s;
	while (*res)
	{
		if (*res == smb)
			return (res);
		res++;
	}
	if (*res == '\0' && smb == '\0')
		return (res);
	return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*frst;
	unsigned char	*scnd;
	int				i;

	i = 0;
	frst = (unsigned char*)src;
	scnd = (unsigned char*)dest;
	while (n--)
	{
		scnd[i] = frst[i];
		i++;
	}
	return (dest);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t count;

	count = 0;
	if (size == 0)
	{
		while (src[count])
			count++;
		return (count);
	}
	while (count < size - 1 && src[count] != '\0')
	{
		dst[count] = src[count];
		count++;
	}
	if (count < size)
		dst[count] = '\0';
	while (src[count] != '\0')
		count++;
	return (count);
}
