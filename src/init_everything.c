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

#include "../so_long.h"

void	init_variables(t_vars *vars)
{
	vars->player.points = 0;
	vars->player.steps = 0;
	vars->player.sprite = 0;
	vars->configs.coll_count = 0;
	vars->configs.players_count = 0;
	vars->configs.exit_count = 0;
	vars->configs.width = 0;
}

void	init_sprites(t_vars *vars)
{
	int		a;
	int		b;
	void	*(*ptr)(void*, char*, int*, int*);

	a = 50;
	b = 50;
	ptr = mlx_png_file_to_image;
	vars->sprites[m_empty] = ptr(vars->mlx, "img/empty.png", &a, &b);
	vars->sprites[m_wall] = ptr(vars->mlx, "img/wall.png", &a, &b);
	vars->sprites[m_collectable] = ptr(vars->mlx, "img/coll.png", &a, &b);
	vars->sprites[m_off_exit] = ptr(vars->mlx, "img/on_exit.png", &a, &b);
	vars->sprites[m_on_exit] = ptr(vars->mlx, "img/on_exit.png", &a, &b);
	vars->player.sprite = ptr(vars->mlx, "img/player.png", &a, &b);
}
