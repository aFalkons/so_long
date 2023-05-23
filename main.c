/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:24:14 by afalconi          #+#    #+#             */
/*   Updated: 2023/04/18 14:04:12 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(t_game *game)
{
	int	i;

	i = 0;
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->map[i])
	{
		while (i < game->win_y / SPRITESIZE)
		{
			if (game->map[i])
				free(game->map[i]);
			i ++;
		}
	}
	free(game->map);
	exit(EXIT_SUCCESS);
}

void	ft_error(char *str, t_game *game, int dan)
{
	write(2, str, ft_strlen(str));
	if (dan == 1)
		ft_exit(game);
	exit(EXIT_FAILURE);
}

int	gameset(t_game	*game)
{
	time_t t = time (NULL);

	if (t % 2 == 1)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->player.enemies,
		game->player.eneposx * SPRITESIZE, game->player.eneposy * SPRITESIZE);
	}
	else if (t % 3 == 1)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->player.enemiesl,
			game->player.eneposx * SPRITESIZE, game->player.eneposy * SPRITESIZE);
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->player.enemiesr,
			game->player.eneposx * SPRITESIZE, game->player.eneposy * SPRITESIZE);
	}
	return (0);
}

void	acions(t_game	*game)
{
	ft_put_background(game);
	ft_put_map(game);
	mlx_hook(game->mlx_win, 17, 0, ft_exit, game);
	game->player.cmoves = ft_itoa(game->player.moves, game);
	mlx_string_put(game->mlx, game->mlx_win, 10,
		16, 0xFFFFFF, game->player.cmoves);
	mlx_key_hook(game->mlx_win, key_hook, game);
	if (game->player.eneposx)
		mlx_loop_hook(game->mlx, gameset, game);
	mlx_loop(game->mlx);
}

int	main(int ac, char **av)
{
	t_game		game;

	if (ac != 2)
		return (0);
	game.mlx = mlx_init();
	game.player.colcnt = 0;
	game.player.col = 0;
	game.loop = 0;
	game.frame = 0;
	game.player.moves = 0;
	game.player.direction = 1;
	game.mlx_win = NULL;
	map_maker(av[1], &game);
	game.mlx_win = mlx_new_window(game.mlx, game.win_x, game.win_y, "so_long");
	setup(&game);
	acions(&game);
	return (0);
}
