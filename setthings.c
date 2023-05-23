/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setthings.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:01:10 by afalconi          #+#    #+#             */
/*   Updated: 2023/04/17 22:30:46 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_background(t_game *game)
{
	int		y;
	int		x;

	y = 0;
	while (y < game->win_y)
	{
		x = 0;
		while (x < game->win_x)
		{
			mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->player.background, x, y);
			x += SPRITESIZE;
		}
		y += SPRITESIZE;
	}
}

void	ft_put_map(t_game *game)
{
	game->x = 0;
	game->y = 0;
	while (game->y < (game->win_y / SPRITESIZE))
	{
		while (game->x < (game->win_x / SPRITESIZE))
		{
			if (game->map[game->y][game->x] == 'P')
				ft_put_player(game);
			else if (game->map[game->y][game->x] == '1')
				ft_put_things(game, game->player.wall);
			else if (game->map[game->y][game->x] == 'E')
				ft_put_things(game, game->player.exit);
			else if (game->map[game->y][game->x] == 'C')
				ft_put_things(game, game->player.collet);
			else if (game->map[game->y][game->x] == 'G')
				ft_put_things(game, game->player.enemies);
			game->x++;
		}
		game->y++;
		game->x = 0;
	}
}

void	ft_put_things(t_game *game, void *obj)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, obj,
		game->x * SPRITESIZE, game->y * SPRITESIZE);
}

void	ft_put_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->player.background,
		game->x * SPRITESIZE, game->y * SPRITESIZE);
	if (game->player.direction == 0)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->player.player_up, game->x * SPRITESIZE, game->y * SPRITESIZE);
	}
	else if (game->player.direction == 1)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->player.player_right,
			game->x * SPRITESIZE, game->y * SPRITESIZE);
	}
	else if (game->player.direction == 2)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->player.player_down,
			game->x * SPRITESIZE, game->y * SPRITESIZE);
	}
	else if (game->player.direction == 3)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->player.player_left,
			game->x * SPRITESIZE, game->y * SPRITESIZE);
	}
}

void	setup(t_game *game)
{
	int		img_width;
	int		img_height;

	game->player.player_up = mlx_xpm_file_to_image(game->mlx, "img/pup.xpm",
			&img_width, &img_height);
	game->player.player_right = mlx_xpm_file_to_image(game->mlx,
			"img/pright.xpm", &img_width, &img_height);
	game->player.player_down = mlx_xpm_file_to_image(game->mlx, "img/pdown.xpm",
			&img_width, &img_height);
	game->player.background = mlx_xpm_file_to_image(game->mlx, "img/ground.xpm",
			&img_width, &img_height);
	game->player.player_left = mlx_xpm_file_to_image(game->mlx, "img/pleft.xpm",
			&img_width, &img_height);
	game->player.wall = mlx_xpm_file_to_image(game->mlx, "./img/wall.xpm",
			&img_width, &img_height);
	game->player.enemies = mlx_xpm_file_to_image(game->mlx, "./img/enemis.xpm",
			&img_width, &img_height);
	game->player.collet = mlx_xpm_file_to_image(game->mlx, "./img/key.xpm",
			&img_width, &img_height);
	game->player.exit = mlx_xpm_file_to_image(game->mlx, "img/tent.xpm",
			&img_width, &img_height);
	game->player.enemiesr = mlx_xpm_file_to_image(game->mlx, "./img/enemisr.xpm",
			&img_width, &img_height);
	game->player.enemiesl = mlx_xpm_file_to_image(game->mlx, "./img/enemisl.xpm",
			&img_width, &img_height);
}
