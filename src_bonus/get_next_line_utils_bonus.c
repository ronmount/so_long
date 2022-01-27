/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hriser <hriser@21-school.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:58:41 by hriser            #+#    #+#             */
/*   Updated: 2021/10/19 17:05:47 by hriser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;

	uc = (unsigned char) c;
	while (*s && *s != uc)
		s++;
	if (*s == uc)
		return ((char *) s);
	return (0);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*str;

	i = -1;
	str = malloc(ft_strlen(s) + 1);
	if (!str)
		return (0);
	while (s[++i])
		str[i] = s[i];
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;

	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (0);
	i = 0;
	while (*s1 != '\0')
		str[i++] = *s1++;
	while (*s2 != '\0')
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (dstsize)
	{
		i = -1;
		while (src[++i] != '\0' && i < (dstsize - 1))
			dest[i] = src[i];
		dest[i] = '\0';
	}
	return (src_len);
}
