/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:14:41 by gcamargo          #+#    #+#             */
/*   Updated: 2023/01/06 13:14:43 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy_window(t_game *game)
{
	clean_game(game, 2);
	exit(0);
}

int	build_window(t_game *game)
{
	game->width = PIXEL_SIZE * game->map->count_columns;
	game->height = PIXEL_SIZE * game->map->count_lines;
	game->mlx = mlx_init();
	if (!game->mlx)
		return (1);
	mlx_get_screen_size(game->mlx, &game->screen_width, &game->screen_height);
	if ((game->width > game->screen_width)
		|| (game->height > game->screen_height))
		return (1);
	game->window = mlx_new_window(game->mlx, game->width,
			game->height, "so_long");
	if (!game->window || !game->mlx)
		return (1);
	return (0);
}
