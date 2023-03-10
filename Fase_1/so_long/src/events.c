/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:13:17 by gcamargo          #+#    #+#             */
/*   Updated: 2023/01/06 13:13:19 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_check_key(t_game *game, int oldX, int oldY)
{
	if ((game->map->location[game->player->y][game->player->x] == '1') ||
		(game->map->location[game->player->y][game->player->x] == 'E' &&
			game->player->collected != game->map->count_collectibles))
	{
		game->player->x = oldX;
		game->player->y = oldY;
	}
	else
	{
		if (game->map->location[game->player->y][game->player->x] == 'C')
			game->player->collected++;
		if (game->map->location[game->player->y][game->player->x] == 'E')
		{
			if (game->player->collected == game->map->count_collectibles)
			{
				ft_putstr("You Win!\n");
				destroy_window(game);
			}
		}
		game->map->location[oldY][oldX] = '0';
		game->map->location[game->player->y][game->player->x] = 'P';
		game->player->moved++;
	}
}

int	key_press(int keycode, t_game *game)
{
	int	old_x;
	int	old_y;

	old_x = game->player->x;
	old_y = game->player->y;
	if (keycode == ESC)
		destroy_window(game);
	if (keycode == UP)
		game->player->y--;
	if (keycode == DOWN)
		game->player->y++;
	if (keycode == LEFT)
		game->player->x--;
	if (keycode == RIGHT)
		game->player->x++;
	ft_check_key(game, old_x, old_y);
	mlx_clear_window(game->mlx, game->window);
	build_map(game);
	build_display_movement(game);
	return (0);
}

int	expose_hook(t_game *game)
{
	build_map(game);
	return (0);
}

void	load_events(t_game *game)
{
	mlx_hook(game->window, 17, 1L << 2, destroy_window, game);
	mlx_hook(game->window, 2, 1L << 0, key_press, game);
}
