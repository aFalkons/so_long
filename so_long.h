/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:06:26 by afalconi          #+#    #+#             */
/*   Updated: 2023/05/23 03:31:32 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include "gnl/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>
#include <time.h>

# define SPRITESIZE 32

typedef struct s_player
{
	void	*enemies;
	void	*enemiesr;
	void	*enemiesl;
	void	*collet;
	void	*exit;
	void	*wall;
	void	*player_up;
	void	*player_left;
	void	*player_right;
	void	*player_down;
	void	*background;
	int		direction;
	int		eneposx;
	int		eneposy;
	int		plyposx;
	int		plyposy;
	int		ply;
	int		col;
	int		colcnt;
	int		moves;
	char	*cmoves;
}				t_player;

typedef struct s_game {
	void		*mlx;
	void		*mlx_win;
	int			win_x;
	int			win_y;
	int			x;
	int			y;
	void		*object;
	char		**map;
	int			dor;
	int			loop;
	int			frame;
	t_player	player;
}					t_game;

int		counter(char *path,	t_game	*game);
void	fill(char *path, t_game	*game);
void	map_maker(char *path, t_game	*game);
void	setup(t_game *game);
int		ft_checkber(char *big, size_t len);
void	ft_put_background(t_game *game);
int		gameset(t_game	*game);
void	ft_put_map(t_game *game);
void	ft_put_things(t_game *game, void *obj);
int		ft_exit(t_game *game);
void	ft_put_player(t_game *game);
void	acions(t_game	*game);
int		key_hook(int key, t_game *game);
void	moveplayer(t_game *game, int y,int x);
void	printn2(int n, char *ret, int cont, int win);
void	printn(int n, int win, t_game *game);
void	ft_error(char *str, t_game *game, int dan);
int		fill2(t_game *game, int i, char *str, int contr);
char	*ft_itoa(int n, t_game *game);
char	*itoa2(int n, char *ret, int cont, t_game *game);
void	checktopbot(char *str, t_game *game, int n);
void	putnamber(t_game *game);
void	moveplayer2(t_game *game, char *players, int y, int x);

#endif
