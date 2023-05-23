/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:57:35 by afalconi          #+#    #+#             */
/*   Updated: 2023/03/31 01:16:31 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int key, t_game *game)
{
	free(game->player.cmoves);
	if (key == 53)
		ft_exit(game);
	else if (key == 13)
	{
		game->player.direction = 0;
		moveplayer(game, -1, 0);
	}
	else if (key == 0)
	{
		game->player.direction = 3;
		moveplayer(game, 0, -1);
	}
	else if (key == 1)
	{
		game->player.direction = 2;
		moveplayer(game, 1, 0);
	}
	else if (key == 2)
	{
		game->player.direction = 1;
		moveplayer(game, 0, 1);
	}
	putnamber(game);
	return (0);
}

void	moveplayer(t_game *game, int y, int x)
{
	char			*players;

	players = &game->map[game->player.plyposy + y][game->player.plyposx + x];
	if ((*players != '1' && *players != 'E')
		|| (*players == 'E' && game->player.colcnt == game->player.col))
		game->player.moves ++;
	if (*players != '1' && *players != 'G' && *players != 'E')
	{
		moveplayer2(game, players, y, x);
	}
	if (*players == 'G')
		printn(game->player.moves, 2, game);
	if (*players == 'E' && game->player.colcnt == game->player.col)
		printn(game->player.moves, 1, game);
	if (*players == 'G'
		|| (*players == 'E' && game->player.colcnt == game->player.col))
		ft_exit(game);
}

void	checktopbot(char *str, t_game *game, int n)
{
	int	i;

	i = -1;
	while (++i < ft_strlen(str) - 1)
	{
		if (str[i] != '1')
		{
			free(str);
			ft_error("the bot or top row of the map is not all wall\n", game, n);
		}
	}
}

void	putnamber(t_game *game)
{
		game->player.cmoves = ft_itoa(game->player.moves, game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->player.wall,
		0 * SPRITESIZE, 0 * SPRITESIZE);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->player.wall,
		1 * SPRITESIZE, 0 * SPRITESIZE);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->player.wall,
		2 * SPRITESIZE, 0 * SPRITESIZE);
	mlx_string_put(game->mlx, game->mlx_win, 10,
		16, 0xFFFFFF, game->player.cmoves);
}

void	moveplayer2(t_game *game, char *players, int y, int x)
{
	if (*players == 'C')
		game->player.colcnt ++;
	game->map[game->player.plyposy][game->player.plyposx] = '0';
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->player.background, game->player.plyposx * SPRITESIZE,
		game->player.plyposy * SPRITESIZE);
	*players = 'P';
	game->x = game->player.plyposx + x;
	game->y = game->player.plyposy + y;
	ft_put_player(game);
	game->player.plyposx = game->player.plyposx + x;
	game->player.plyposy = game->player.plyposy + y;
	printn(game->player.moves, 0, game);
}
