/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hriser <hriser@21-school.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:20:02 by hriser            #+#    #+#             */
/*   Updated: 2021/12/06 18:34:16 by hriser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 100

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include "mlx/mlx.h"

enum e_sprites {
	m_empty,
	m_wall,
	m_collectable,
	m_off_exit,
	m_on_exit,
};

typedef int	t_bool;

typedef struct s_player {
	int		x;
	int		y;
	int		points;
	int		steps;
	void	*sprite;
}	t_player;

typedef struct s_configs
{
	int			height;
	int			width;
	int			coll_count;
	int			exit_count;
	int			players_count;
	int			**map;
}	t_configs;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	void		*sprites[6];
	t_player	player;
	t_configs	configs;
}	t_vars;

char	*get_next_line(int fd);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t destsize);
int		ft_strlen(const char *s);
void	ft_putnbr_fd(int n, int fd);
int		map_parser(char *path, t_vars *vars);
void	error(char *e);
int		draw(t_vars *vars);
void	init_variables(t_vars *vars);
void	init_sprites(t_vars *vars);
void	open_the_door(t_vars *vars);
void	print_steps(t_vars *vars);
void	create_box(int type, int *counter, int *item);

#endif
