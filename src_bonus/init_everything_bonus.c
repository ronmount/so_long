/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ................                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hriser <hriser@21-school.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:58:41 by hriser            #+#    #+#             */
/*   Updated: 2021/10/20 18:17:32 by hriser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	init_variables(t_vars *vars)
{
	vars->player.points = 0;
	vars->player.steps = 0;
	vars->player.sprite = 0;
	vars->player.alive = 1;
	vars->configs.coll_count = 0;
	vars->configs.players_count = 0;
	vars->configs.exit_count = 0;
	vars->col = 0;
	vars->configs.width = 0;
}

void	init_sprites(t_vars *vars)
{
	int		a;
	int		b;
	int		i;
	void	*(*ptr)(void*, char*, int*, int*);

	a = 50;
	b = 50;
	ptr = mlx_png_file_to_image;
	vars->sprites[m_empty] = ptr(vars->mlx, "img/empty.png", &a, &b);
	vars->sprites[m_wall] = ptr(vars->mlx, "img/wall.png", &a, &b);
	vars->sprites[m_off_exit] = ptr(vars->mlx, "img/off_exit.png", &a, &b);
	vars->sprites[m_on_exit] = ptr(vars->mlx, "img/on_exit.png", &a, &b);
	vars->sprites[m_enemy] = ptr(vars->mlx, "img/patrol.png", &a, &b);
	vars->sprites[m_coll_win] = ptr(vars->mlx, "img/coll_win.png", &a, &b);
	vars->player.dead_sprite = ptr(vars->mlx, "img/player_dead.png", &a, &b);
	i = -1;
	while (++i < 5)
	{
		vars->player.sprites[i] = ptr(vars->mlx, "img/player1.png", &a, &b);
		vars->player.sprites[i + 5] = ptr(vars->mlx, "img/player2.png", &a, &b);
		vars->col_s[i] = ptr(vars->mlx, "img/coll_1.png", &a, &b);
		vars->col_s[i + 5] = ptr(vars->mlx, "img/coll_2.png", &a, &b);
	}
}
