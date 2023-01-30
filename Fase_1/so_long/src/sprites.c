/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:26:29 by gcamargo          #+#    #+#             */
/*   Updated: 2023/01/07 00:32:50 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_game *game, int *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx,
		game->window, image,
		x * PIXEL_SIZE, y * PIXEL_SIZE);
}

int	load_images(t_game *game)
{
	game->images->wall = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm",
			&game->images->x, &game->images->y);
	game->images->collectible = mlx_xpm_file_to_image(game->mlx,
			"assets/collectible.xpm", &game->images->x, &game->images->y);
	game->images->exit = mlx_xpm_file_to_image(game->mlx,
			"assets/exit.xpm",
			&game->images->x, &game->images->y);
	game->images->player = mlx_xpm_file_to_image(game->mlx,
			"assets/player.xpm",
			&game->images->x, &game->images->y);
	if (!game->images->wall
		|| !game->images->collectible
		|| !game->images->exit
		|| !game->images->player)
		return (1);
	return (0);
}
