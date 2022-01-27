/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hriser <hriser@21-school.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 03:26:19 by hriser            #+#    #+#             */
/*   Updated: 2021/12/06 17:47:50 by hriser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(-1 * n, fd);
	}
	else
	{
		if (n >= 10)
			ft_putnbr_fd(n / 10, fd);
		write(fd, (char []){(n % 10) + '0'}, 1);
	}
}

static int	numlen(int n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
		i++;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		nlen;
	int		i;
	char	*str;

	nlen = numlen(n);
	str = malloc(sizeof(char) * (nlen + 1));
	if (!str)
		return (0);
	i = 0;
	if (n < 0)
		str[0] = '-';
	if (n == 0)
		str[0] = '0';
	str[nlen] = '\0';
	while (n != 0)
	{
		if (n % 10 >= 0)
			str[nlen - i - 1] = n % 10 + '0';
		else
			str[nlen - i - 1] = -1 * (n % 10) + '0';
		i++;
		n /= 10;
	}
	return (str);
}
