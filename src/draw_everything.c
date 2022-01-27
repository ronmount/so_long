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

void	draw_map(t_vars *vars)
{
	int	i;
	int	j;

	i = -1;
	while (++i < vars->configs.height)
	{
		j = -1;
		while (++j < vars->configs.width)
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->sprites[vars->configs.map[i][j]], j * 50, i * 50);
	}
}

int	draw_player(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->player.sprite,
		vars->player.x * 50, vars->player.y * 50);
	return (0);
}

int	draw(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->player.x;
	y = vars->player.y;
	print_steps(vars);
	if (vars->configs.map[y][x] == m_collectable)
	{
		vars->configs.map[y][x] = m_empty;
		vars->player.points++;
		if (vars->player.points == vars->configs.coll_count)
			open_the_door(vars);
	}
	draw_map(vars);
	draw_player(vars);
	if (vars->configs.map[y][x] == m_on_exit)
		exit(0);
	return (1);
}
