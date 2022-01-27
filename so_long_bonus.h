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

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
	m_enemy,
	m_coll_win
};

typedef int	t_bool;

typedef struct s_player {
	int		x;
	int		y;
	int		points;
	int		steps;
	int		sprite;
	int		alive;
	void	*dead_sprite;
	void	*sprites[10];
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
	void		*sprites[8];
	void		*col_s[10];
	int			col;
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
int		draw_player(t_vars *vars);
int		draw_with_usleep(t_vars *vars);
void	draw_map(t_vars *vars);
int		draw(t_vars *vars);
void	open_the_door(t_vars *vars);
void	init_variables(t_vars *vars);
void	init_sprites(t_vars *vars);
char	*ft_itoa(int n);
void	set_pepas_win(t_vars *vars);
void	draw_win(t_vars *vars);
void	draw_game_over(t_vars *vars);
void	draw_steps(t_vars *vars);
void	create_box(int type, int *counter, int *item);
void	create_player(int *item, int c, int i, t_vars *vars);
int		draw_with_usleep(t_vars *vars);
void	draw_collectables(t_vars *vars);

#endif
