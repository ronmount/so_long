/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hriser <hriser@21-school.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:58:29 by hriser            #+#    #+#             */
/*   Updated: 2021/12/07 13:58:06 by hriser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	get_map_height(char *path)
{
	int		fd;
	int		height;
	char	*line;

	height = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		error("Wrong file path.");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		height += 1;
		free(line);
	}
	close(fd);
	return (height);
}

int	line_valid(char *line, t_bool first_or_last, t_vars *vars)
{
	int	len;
	int	i;

	len = ft_strlen(line);
	if (line[len - 1] == '\n')
	{
		line[len - 1] = '\0';
		len -= 1;
	}
	if (vars->configs.width != 0 && vars->configs.width != len)
		error("Map has curved edges!");
	vars->configs.width = len;
	i = -1;
	while (++i < len)
	{
		if (i == 0 || len - i == 1 || first_or_last)
			if (line[i] != '1')
				return (1);
		if (line[i] != '0' && line[i] != '1' && line[i] != 'C'
			&& line[i] != 'E' && line[i] != 'P' && line[i] != 'T')
			return (1);
	}
	return (0);
}

int	*get_map_line(char *line, t_vars *vars, int c)
{
	int		i;
	int		*map_line;

	i = -1;
	map_line = malloc(sizeof(int) * vars->configs.width);
	if (!map_line)
		error("Malloc error");
	while (++i < vars->configs.width)
	{
		if (line[i] == '0')
			create_box(m_empty, 0, &map_line[i]);
		if (line[i] == '1')
			create_box(m_wall, 0, &map_line[i]);
		if (line[i] == 'C')
			create_box(m_collectable, &vars->configs.coll_count, &map_line[i]);
		if (line[i] == 'E')
			create_box(m_off_exit, &vars->configs.exit_count, &map_line[i]);
		if (line[i] == 'T')
			create_box(m_enemy, 0, &map_line[i]);
		if (line[i] == 'P')
			create_player(&map_line[i], c, i, vars);
	}
	return (map_line);
}

void	check_counters(t_vars *vars)
{
	if (vars->configs.coll_count == 0)
		error("No collectables on map.");
	if (vars->configs.exit_count == 0)
		error("No exit on map.");
	if (vars->configs.players_count == 0)
		error("No player on map.");
}

int	map_parser(char *path, t_vars *vars)
{
	char	*line;
	int		fd;
	int		i;

	vars->configs.height = get_map_height(path);
	vars->configs.map = malloc(sizeof(int *) * vars->configs.height);
	if (!vars->configs.map)
		error("Malloc error");
	fd = open(path, O_RDONLY);
	if (fd == -1)
		error("Wrong file path.");
	i = -1;
	while (++i < vars->configs.height)
	{
		line = get_next_line(fd);
		if (!line)
			error("Malloc error");
		if (line_valid(line, (i == 0 || vars->configs.height - i == 1), vars))
			error("Wrong chars in map.");
		vars->configs.map[i] = get_map_line(line, vars, i);
		free(line);
	}
	close(fd);
	check_counters(vars);
	return (0);
}
