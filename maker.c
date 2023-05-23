/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maker.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:08:05 by afalconi          #+#    #+#             */
/*   Updated: 2023/04/18 01:03:37 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	counter(char *path, t_game *game)
{
	char	*str;
	int		j;
	int		i;
	int		fd;
	int		contr;

	fd = open(path, O_RDONLY);
	if (ft_checkber(path, ft_strlen(path)) == 0)
		ft_error("Error is not a .ber\n", game, 0);
	i = 0;
	j = 0;
	contr = 0;
	str = get_next_line(fd);
	if (!str)
		ft_error("map error\n", game, 0);
	checktopbot(str, game, 0);
	game->win_x = (ft_strlen(str) - 1) * SPRITESIZE;
	while (str)
	{
		i++;
		contr = fill2(game, i, str, contr);
		free(str);
		str = get_next_line(fd);
		if (!str)
			break ;
		if (game->win_x / SPRITESIZE != ft_strlen(str) - 1)
			ft_error("the line len is different than the precedent\n", game, 0);
	}
	game->win_y = i * SPRITESIZE;
	if (contr == 1)
		ft_error("left or right are not all walls\n", game, 0);
	close(fd);
	fd = open(path, O_RDONLY);
	str = get_next_line(fd);
	while (j < i - 1)
	{
		free(str);
		str = get_next_line(fd);
		j++;
	}
	checktopbot(str, game, 0);
	close(fd);
	return (i);
}

void	fill(char *path, t_game	*game)
{
	int		i;
	int		fd;
	char	*str;
	int		j;

	fd = open(path, O_RDONLY);
	str = get_next_line(fd);
	i = -1;
	while (str)
	{
		j = 0;
		game->map[++i] = str;
		game->map[i][game->win_x / SPRITESIZE] = '\0';
		str = get_next_line(fd);
		if (!str)
			break ;
	}
	close(fd);
}

int	fill2(t_game *game, int i, char *str, int contr)
{
	int		j;

	j = 0;
	if (str[0] != '1' || str[(game->win_x / SPRITESIZE) - 1] != '1')
		contr = 1;
	while (j < game->win_x / SPRITESIZE)
	{
		if (str[j] == 'P')
		{
			game->player.plyposx = j;
			game->player.plyposy = i - 1;
			game->player.ply ++;
		}
		else if (str[j] == 'C')
			game->player.col ++;
		else if (str[j] == 'E')
			game->dor ++;
		else if (str[j] == 'G')
		{
			game->player.eneposx = j;
			game->player.eneposy = i - 1;
		}
		else if (str[j] != '1' && str[j] != '0'
			&& str[j] != 'E' && str[j] != 'G')
			ft_error("characters not accepted in the map\n", game, 0);
		j ++;
	}
	return (contr);
}

void	map_maker(char *path, t_game	*game)
{
	int		line;

	game->dor = 0;
	game->player.ply = 0;
	line = counter(path, game);
	if (game->win_x / SPRITESIZE < 4 || game->win_y / SPRITESIZE < 4)
		ft_error("Error\nmap to littel\n", game, 0);
	game->map = (char **) malloc(line * 8);
	if (!game->map)
		ft_error("Error\nmap has to been mallocated\n", game, 1);
	fill(path, game);
	if (game->dor > 1 || game->player.ply > 1 || game->player.col == 0)
		ft_error("Error\nelements error\n", game, 1);
}
