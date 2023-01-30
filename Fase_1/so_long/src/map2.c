/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:13:54 by gcamargo          #+#    #+#             */
/*   Updated: 2023/01/06 13:13:55 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	loop_content_map(t_game *game)
{
	while (game->content != NULL && game->line < game->map->count_lines)
	{
		game->column = 0;
		while (game->column < game->map->count_columns)
		{
			if (game->content[game->column] != '\n')
				game->map->location[game->line][game->column]
					= game->content[game->column];
			if (game->content[game->column] == '\n'
				&& game->column != game->map->count_columns)
			{
				free(game->content);
				return (1);
			}
			game->column++;
		}
		free(game->content);
		game->content = get_next_line(game->map->fd);
		game->line++;
	}
	return (0);
}
