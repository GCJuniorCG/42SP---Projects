/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:14:34 by gcamargo          #+#    #+#             */
/*   Updated: 2023/01/06 13:14:36 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_dfs(int column, int line, int *trigger, t_map *map)
{
	if (*trigger == 1)
		return (1);
	if (map->location[line][column] == '1')
		return (0);
	if (map->location[line][column] == 'V')
		return (0);
	if (map->location[line][column] == 'E')
	{
		*trigger = 1;
		return (1);
	}
	map->location[line][column] = 'V';
	is_valid_dfs(column + 1, line, trigger, map);
	is_valid_dfs(column - 1, line, trigger, map);
	is_valid_dfs(column, line + 1, trigger, map);
	is_valid_dfs(column, line - 1, trigger, map);
	if (*trigger == 1)
		return (1);
	return (0);
}

int	check_path(t_game *game)
{
	int		line;
	int		column;
	int		trigger;
	int		check;
	t_map	*map;

	trigger = 0;
	check = 0;
	map = game->map;
	column = game->player->x;
	line = game->player->y;
	check = is_valid_dfs(column, line, &trigger, map);
	if (check == 1)
		return (0);
	return (1);
}
