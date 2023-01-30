/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:14:20 by gcamargo          #+#    #+#             */
/*   Updated: 2023/01/06 19:26:09 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define BUFFER_SIZE 42
# define PIXEL_SIZE 32

# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include "../libft/libft.h"

typedef struct s_map
{
	int	fd;
	int	**location;
	int	count_lines;
	int	count_columns;
	int	count_collectibles;
	int	count_exits;
	int	count_zeros;
	int	count_walls;	
	int	count_wrong_c;
	int	count_player;
}	t_map;

typedef struct s_images
{
	int		*wall;
	int		x;
	int		y;
	void	*collectible;
	void	*exit;
	void	*player;
}	t_images;

typedef struct s_player
{
	int	x;
	int	y;
	int	moved;
	int	collected;
}	t_player;

typedef struct s_game
{
	void			*mlx;
	void			*window;
	int				width;
	int				height;
	int				screen_width;
	int				screen_height;
	int				c_collectible;
	int				x;
	int				error;
	int				error_c;
	int				trigger;
	char			*content;
	int				line;
	int				column;
	struct s_images	*images;
	struct s_map	*map;
	struct s_player	*player;
}	t_game;

int		load_images(t_game *game);
int		build_map(t_game *game);
int		load_map(char **argv, t_game *game);
int		key_press(int keycode, t_game *game);
int		destroy_window(t_game *game);
int		build_window(t_game *game);
void	put_image(t_game *game, int *image, int x, int y);
int		read_map_file(t_game *game, char **argv);
int		check_rules(t_game *game);
int		clean_game(t_game *game, int trigger);
int		msg_error(t_game *game, char *msg, int trigger);
int		check_format_file(int argc, char **argv);
int		check_map_walls(t_game *game);
int		check_path(t_game *game);
int		expose_hook(t_game *game);
int		zero_map_location(t_game *game);
int		build_display_movement(t_game *game);
t_game	*init_game(t_game *game);
void	load_events(t_game *game);
int		msg_error(t_game *game, char *msg, int trigger);
void	empty_get_next_line(t_game *game);
int		get_content_file(t_game *game);
int		map_count_itens(t_game *game, char *line, int x);
int		loop_content_map(t_game *game);

#endif //SO_LONG_H
