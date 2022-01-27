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

int	draw_player(t_vars *vars)
{
	int	sprite;

	if (vars->player.alive)
	{
		if (vars->player.sprite == 9)
			vars->player.sprite = 0;
		else
			vars->player.sprite++;
		sprite = vars->player.sprite;
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->player.sprites[sprite],
			vars->player.x * 50, vars->player.y * 50);
	}
	else
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->player.dead_sprite,
			vars->player.x * 50, vars->player.y * 50);
	return (0);
}

void	draw_collectables(t_vars *vars)
{
	int	i;
	int	j;

	i = -1;
	while (++i < vars->configs.height)
	{
		j = -1;
		while (++j < vars->configs.width)
		{
			if (vars->configs.map[i][j] == m_collectable)
			{
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->col_s[vars->col], j * 50, i * 50);
			}
		}
	}
	if (vars->col == 9)
		vars->col = 0;
	else
		vars->col++;
}

void	draw_map(t_vars *vars)
{
	int	i;
	int	j;

	i = -1;
	while (++i < vars->configs.height)
	{
		j = -1;
		while (++j < vars->configs.width)
			if (vars->configs.map[i][j] != m_collectable)
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->sprites[vars->configs.map[i][j]], j * 50, i * 50);
	}
}

void	check_changes(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->player.x;
	y = vars->player.y;
	if (vars->configs.map[y][x] == m_collectable)
	{
		vars->configs.map[y][x] = m_empty;
		vars->player.points++;
		if (vars->player.points == vars->configs.coll_count)
			open_the_door(vars);
	}
	if (vars->configs.map[y][x] == m_enemy)
	{
		vars->player.alive = 0;
		set_pepas_win(vars);
	}
	if (vars->configs.map[y][x] == m_on_exit)
		vars->player.alive = 2;
}

int	draw(t_vars *vars)
{
	check_changes(vars);
	if (vars->player.alive == 0)
		draw_game_over(vars);
	else if (vars->player.alive == 1)
		draw_steps(vars);
	else
		draw_win(vars);
	draw_map(vars);
	draw_collectables(vars);
	draw_player(vars);
	return (1);
}
