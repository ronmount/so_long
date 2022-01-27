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

void	create_box(int type, int *counter, int *item)
{
	*item = type;
	if (counter)
		*counter += 1;
}

void	create_player(int *item, int c, int i, t_vars *vars)
{
	vars->player.x = i;
	vars->player.y = c;
	*item = m_empty;
	vars->configs.players_count++;
}
