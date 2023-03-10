/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:12:11 by gcamargo          #+#    #+#             */
/*   Updated: 2023/01/06 22:10:57 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	zero_map_location(t_game *game)
{
	int	x;

	x = 0;
	while (x < game->map->count_lines)
	{
		free(game->map->location[x]);
		x++;
	}
	free(game->map->location);
	return (0);
}

int	clean_game(t_game *game, int trigger)
{
	if (trigger == 1)
		game->mlx = malloc(sizeof(void *));
	if (trigger == 2)
	{
		mlx_destroy_image(game->mlx, game->images->wall);
		mlx_destroy_image(game->mlx, game->images->player);
		mlx_destroy_image(game->mlx, game->images->collectible);
		mlx_destroy_image(game->mlx, game->images->exit);
		trigger = 3;
	}
	if (trigger == 3)
	{
		mlx_destroy_window(game->mlx, game->window);
		mlx_destroy_display(game->mlx);
		zero_map_location(game);
	}
	free(game->map);
	free(game->player);
	free(game->images);
	free(game->mlx);
	free(game);
	return (0);
}
