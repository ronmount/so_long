/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hriser <hriser@21-school.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:58:41 by hriser            #+#    #+#             */
/*   Updated: 2021/10/20 18:17:32 by hriser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

char	*ft_save(int fd, char *save, char *buffer)
{
	int		c;
	char	*tmp;

	c = 1;
	while (c != 0)
	{
		c = read(fd, buffer, BUFFER_SIZE);
		if (c == -1)
		{
			free(buffer);
			return (0);
		}
		buffer[c] = '\0';
		if (save == 0)
			save = ft_strdup("");
		tmp = save;
		save = ft_strjoin(tmp, buffer);
		free(tmp);
		if (ft_strchr(save, '\n'))
			break ;
	}
	free(buffer);
	return (save);
}

char	*get_next_string(char *save)
{
	int		i;
	char	*str;

	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	str = malloc(i + 2);
	if (!str)
		return (0);
	ft_strlcpy(str, save, i + 2);
	if (str[0] == '\0')
	{
		free(str);
		return (0);
	}
	return (str);
}

char	*resave(char *save)
{
	int		i;
	char	*tmp;

	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (save[i] == '\0')
	{
		free(save);
		return (0);
	}
	tmp = malloc(ft_strlen(save) - i + 1);
	if (!tmp)
		return (0);
	ft_strlcpy(tmp, save + i + 1, ft_strlen(save) - i + 1);
	free(save);
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		*str;
	char		*buffer;
	static char	*save[OPEN_MAX];

	str = NULL;
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	save[fd] = ft_save(fd, save[fd], buffer);
	if (!save[fd])
		return (0);
	str = get_next_string(save[fd]);
	save[fd] = resave(save[fd]);
	return (str);
}
