/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hriser <hriser@21-school.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 03:26:19 by hriser            #+#    #+#             */
/*   Updated: 2021/12/06 17:47:50 by hriser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_close(int keycode, t_vars *vars)
{
	(void) keycode;
	(void) vars;
	exit(0);
}

void	open_the_door(t_vars *vars)
{
	int	i;
	int	j;

	i = -1;
	while (++i < vars->configs.height)
	{
		j = -1;
		while (++j < vars->configs.width)
			if (vars->configs.map[i][j] == m_off_exit)
				vars->configs.map[i][j] = m_on_exit;
	}
}

void	set_pepas_win(t_vars *vars)
{
	int	i;
	int	j;

	i = -1;
	while (++i < vars->configs.height)
	{
		j = -1;
		while (++j < vars->configs.width)
			if (vars->configs.map[i][j] == m_collectable)
				vars->configs.map[i][j] = m_coll_win;
	}
}

int	ft_move(int keycode, t_vars *vars)
{
	int	x;
	int	y;

	if (keycode == 53)
		exit(0);
	if (vars->player.alive == 1)
	{
		x = vars->player.x;
		y = vars->player.y;
		if (keycode == 13 && vars->configs.map[y - 1][x] != m_wall)
			vars->player.y -= 1;
		if (keycode == 0 && vars->configs.map[y][x - 1] != m_wall)
			vars->player.x -= 1;
		if (keycode == 1 && vars->configs.map[y + 1][x] != m_wall)
			vars->player.y += 1;
		if (keycode == 2 && vars->configs.map[y][x + 1] != m_wall)
			vars->player.x += 1;
		if (x != vars->player.x || y != vars->player.y)
			draw(vars);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	*vars;

	if (argc != 2)
		error("No arguments passed to a program.");
	vars = malloc(sizeof(t_vars));
	init_variables(vars);
	if (map_parser(argv[1], vars))
		return (1);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->configs.width * 50,
			vars->configs.height * 50 + 50, "so_long");
	init_sprites(vars);
	draw(vars);
	mlx_hook(vars->win, 17, 0, ft_close, vars);
	mlx_hook(vars->win, 2, 0, ft_move, vars);
	mlx_loop_hook(vars->mlx, draw_with_usleep, vars);
	mlx_loop(vars->mlx);
	return (0);
}
