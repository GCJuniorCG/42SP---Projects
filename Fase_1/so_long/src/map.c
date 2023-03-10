/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:13:46 by gcamargo          #+#    #+#             */
/*   Updated: 2023/01/09 20:22:58 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_player(t_game *game, int x, int y)
{
	put_image(game, game->images->player, x, y);
	game->player->x = x;
	game->player->y = y;
}

int	build_map(t_game *game)
{
	int	column;
	int	line;

	line = 0;
	while (line < game->map->count_lines)
	{
		column = 0;
		while (column < game->map->count_columns)
		{
			if (game->map->location[line][column] == '1')
				put_image(game, game->images->wall, column, line);
			if (game->map->location[line][column] == 'C')
				put_image(game, game->images->collectible, column, line);
			if (game->map->location[line][column] == 'E')
				put_image(game, game->images->exit, column, line);
			if (game->map->location[line][column] == 'P')
				put_player(game, column, line);
			column++;
		}
		line++;
	}
	return (0);
}

static void	ft_init_map(t_game *game, char **argv)
{
	int	x;
	int	y;

	game->map->fd = open(argv[1], O_RDONLY);
	if (game->map->location != NULL)
		zero_map_location(game);
	game->map->location = malloc(sizeof(int *) * game->map->count_lines);
	x = 0;
	while (x < game->map->count_lines)
	{
		game->map->location[x] = malloc(sizeof(int) * game->map->count_columns);
		x++;
	}
	x = 0;
	while (x < game->map->count_lines)
	{
		y = 0;
		while (y < game->map->count_columns)
		{
			game->map->location[x][y] = 0;
			y++;
		}
		x++;
	}
}

int	load_map(char **argv, t_game *game)
{
	ft_init_map(game, argv);
	game->line = 0;
	game->column = 0;
	game->content = get_next_line(game->map->fd);
	if (loop_content_map(game))
	{
		free(game->content);
		close(game->map->fd);
		return (1);
	}
	if (game->line == 0)
	{
		free(game->content);
		close(game->map->fd);
		return (1);
	}
	close(game->map->fd);
	return (0);
}

int	build_display_movement(t_game *game)
{
	char	*str;

	str = NULL;
	str = ft_itoa(game->player->moved);
	if (!str)
	{
		free(str);
		return (1);
	}
	ft_putstr("Player Moved: ");
	ft_putstr(str);
	ft_putstr("\n");
	free(str);
	return (0);
}
