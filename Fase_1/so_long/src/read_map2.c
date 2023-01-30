/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:14:12 by gcamargo          #+#    #+#             */
/*   Updated: 2023/01/06 13:14:14 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	empty_get_next_line(t_game *game)
{
	while (game->content != NULL)
	{
		free(game->content);
		game->content = get_next_line(game->map->fd);
	}	
}

int	get_content_file(t_game *game)
{
	while (game->content[game->x] != '\0')
	{
		if (game->content[game->x] == '\n' && game->trigger == 0)
		{
			game->trigger = 1;
			game->error_c = game->x;
		}
		if (game->trigger == 1 && game->content[game->x] == '\n'
			&& game->error_c != game->x)
		{
			empty_get_next_line(game);
			return (1);
		}
		map_count_itens(game, game->content, game->x);
		game->x++;
	}
	return (0);
}
