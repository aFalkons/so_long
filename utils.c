/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:47:59 by afalconi          #+#    #+#             */
/*   Updated: 2023/03/31 01:39:37 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_checkber(char *big, size_t len)
{
	if (len < 5)
		return (0);
	if (((big[len - 1] != 'r') || (big[len - 2] != 'e'))
		|| ((big[len - 3] != 'b') || (big[len - 4] != '.')))
		return (0);
	return (1);
}

void	printn2(int n, char *ret, int cont, int win)
{
	int	n2;
	int	cont2;

	cont2 = 0;
	while (--cont != -1)
	{
		n2 = n % 10;
		n /= 10;
		ret[cont] = n2 + 48;
	}
	if (win == 0)
		write(1, "questa e la tua ", 16);
	else if (win == 1)
		write(1, "hai vinto alla tua ", 20);
	else if (win == 2)
		write(1, "hai perso alla tua ", 19);
	while (ret[cont2])
	{
		write(1, &ret[cont2], 1);
		cont2 ++;
	}
	write(1, " mossa\n", 7);
	free(ret);
}

void	printn(int n, int win, t_game *game)
{
	int		n2;
	int		cont;
	int		check;
	char	*ret;

	cont = 0;
	n2 = 0;
	check = 0;
	ret = NULL;
	n2 = n;
	while (n2 > 0)
	{
		n2 /= 10;
		cont ++;
	}
	ret = malloc(sizeof(char) * (cont + 1));
	if (!ret)
		ft_error("Bead malloc for moves\n", game, 1);
	ret[cont] = 0;
	printn2(n, ret, cont, win);
}

char	*itoa2(int n, char *ret, int cont, t_game *game)
{
	int	n2;

	ret = malloc(sizeof(char) * (cont + 1));
	if (!ret)
		ft_error("Bead malloc for moves at screen\n", game, 1);
	ret[cont] = 0;
	while (--cont != -1)
	{
		n2 = n % 10;
		n /= 10;
		ret[cont] = n2 + 48;
	}
	return (ret);
}

char	*ft_itoa(int n, t_game *game)
{
	int		n2;
	int		cont;
	char	*ret;

	cont = 0;
	n2 = 0;
	ret = NULL;
	if (n == 0)
	{
		ret = malloc(2);
		ret[0] = '0';
		ret[1] = 0;
		return (ret);
	}
	n2 = n;
	while (n2 > 0)
	{
		n2 /= 10;
		cont ++;
	}
	return (itoa2(n, ret, cont, game));
}
