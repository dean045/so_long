/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 12:25:25 by brhajji-          #+#    #+#             */
/*   Updated: 2022/02/15 14:54:28 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_ber(char *map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	if (map[i - 1] == 'r' && map[i - 2] == 'e' && map[i - 3] == 'b'
		&& map[i - 4] == '.')
		return (1);
	else
		return (0);
}

int	check_files(char *map)
{
	if (open("assets/coin.xpm", 0) == -1)
		return (10);
	if (open("assets/door_close.xpm", 0) == -1)
		return (20);
	if (open("assets/door_open.xpm", 0) == -1)
		return (20);
	if (open("assets/ground.xpm", 0) == -1)
		return (30);
	if (open("assets/player.xpm", 0) == -1)
		return (40);
	if (open("assets/wall.xpm", 0) == -1)
		return (50);
	if (open(map, __O_DIRECTORY) > 0 || open(map, 0) == -1 || !check_ber(map)
		|| open(map, __O_NOFOLLOW) == -1)
		return (5);
	return (0);
}

int	check_p_e(char **map, int l)
{
	int	x;
	int	y;
	int	p;
	int	e;

	y = -1;
	e = 0;
	p = 0;
	while (++y < l)
	{
		x = -1;
		while (++x < ft_strlen(map[y]) - 1)
		{
			if (map[y][x] != 'P' && map[y][x] != 'E' && map[y][x] != 'C'
					&& map[y][x] != '0' && map[y][x] != '1' && map[y][x] != 'M')
				return (4);
			if (map[y][x] == 'P')
				p++;
			if (map[y][x] == 'E')
				e++;
		}
	}
	if (e < 1 || p != 1)
		return (3);
	return (0);
}

int	check_map(char **map, int l)
{
	int	x;
	int	y;
	int	size;
	int	size_n;

	size = ft_strlen(*map);
	if (!map[0][0])
		return (99);
	y = -1;
	while (++y < l)
	{
		x = -1;
		size_n = ft_strlen(map[y]);
		if ((size_n != size && y != (l - 1))
			|| (y == (l - 1) && size_n != size - 1))
			return (2);
		while (++x < size - 1)
		{
			if ((y == 0 || y == l - 1) && map[y][x] != '1')
				return (1);
			if ((x == 0 || x == (size - 2)) && map[y][x] != '1')
				return (1);
		}
	}
	return (check_p_e(map, l));
}
