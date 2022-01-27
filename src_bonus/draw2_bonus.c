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

void	draw_footer(t_vars *vars)
{
	int		i;
	int		j;

	i = vars->configs.height * 50;
	while (++i < vars->configs.height * 50 + 50)
	{
		j = -1;
		while (++j < vars->configs.width * 50)
			mlx_pixel_put(vars->mlx, vars->win, j, i, 0x00161616);
	}
}

void	draw_steps(t_vars *vars)
{
	char	*steps_string;
	char	*joined_string;

	draw_footer(vars);
	steps_string = ft_itoa(vars->player.steps);
	joined_string = ft_strjoin("Steps: ", steps_string);
	mlx_string_put(vars->mlx, vars->win, 25, vars->configs.height * 50 + 25,
		0xFFFFFFFF, joined_string);
	vars->player.steps++;
	free(steps_string);
	free(joined_string);
}

void	draw_game_over(t_vars *vars)
{
	draw_footer(vars);
	mlx_string_put(vars->mlx, vars->win, 25, vars->configs.height * 50 + 25,
		0xFFFFFFFF, "TIG! Game over!");
}

void	draw_win(t_vars *vars)
{
	char	*steps_string;
	char	*joined_string;

	draw_footer(vars);
	steps_string = ft_itoa(vars->player.steps);
	joined_string = ft_strjoin("Win! Score: ", steps_string);
	mlx_string_put(vars->mlx, vars->win, 25, vars->configs.height * 50 + 25,
		0xFFFFFFFF, joined_string);
	free(steps_string);
	free(joined_string);
}

int	draw_with_usleep(t_vars *vars)
{
	draw_player(vars);
	draw_collectables(vars);
	usleep(25000);
	return (0);
}
