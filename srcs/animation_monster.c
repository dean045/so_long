/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_monster.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:26:46 by brhajji-          #+#    #+#             */
/*   Updated: 2022/02/11 16:58:26 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	trick_case(t_data_engine *engine, int m)
{
	if (engine->map->map[engine->monster[m]->y + 1][engine->monster[m]->x] == '0'
		|| engine->map->map[engine->monster[m]->y + 1][engine->monster[m]->x] == 'P')
		{
			engine->monster[m]->y += 1;
			if (engine->monster[m]->y == engine->player->y &&
				engine->monster[m]->x == engine->player->x)
			{
					mlx_loop_end(engine->init->mlx);
					return ;
			}
			engine->map->map[engine->monster[m]->y][engine->monster[m]->x] = 'M';
			engine->map->map[engine->monster[m]->y - 1][engine->monster[m]->x] = '0';
			put_pixel(engine, engine->element->ground, engine->monster[m]->y - 1,
				engine->monster[m]->x);
		}
		put_pixel(engine, select_monster_face(engine, engine->monster[m]), engine->monster[m]->y, engine->monster[m]->x);
		mlx_put_image_to_window(engine->init->mlx, engine->init->window,
			engine->img->img, 0, 0);
}

void	refresh_face(t_data_engine *engine)
{
	int	m;

	m = -1;
	while (engine->monster[m])
	{
		put_pixel(engine, engine->element->ground, engine->monster[m]->y, engine->monster[m]->x);
		put_pixel(engine, select_monster_face(engine, engine->monster[m]), engine->monster[m]->y, engine->monster[m]->x);
	}
}

int	check_monster_pos(int x, int y, t_data_engine *engine)
{
	int	m;

	m = -1;
	while (engine->monster[++m])
	{
		if (x == engine->monster[m]->x && y == engine->monster[m]->y)
			return (1);
	}
	return (0);
}

int	animate_monster(t_data_engine *engine)
{
	struct timeval	tv2;
	int				m;
	
	m = -1;
	gettimeofday(&(tv2), NULL);
	if(tv2.tv_sec ==  engine->tv.tv_sec + 1)
	{
		while (engine->monster[++m])
		{
			gettimeofday(&(engine->tv), NULL);
			if (engine->map->map[engine->monster[m]->y - 1][engine->monster[m]->x] == '0'
			|| engine->map->map[engine->monster[m]->y - 1][engine->monster[m]->x] == 'P')
			{
				engine->monster[m]->y -= 1;
				if (engine->monster[m]->y == engine->player->y &&
					engine->monster[m]->x == engine->player->x)
				{
					mlx_loop_end(engine->init->mlx);
					return (0);
				}
				engine->map->map[engine->monster[m]->y][engine->monster[m]->x] = 'M';
				engine->map->map[engine->monster[m]->y + 1][engine->monster[m]->x] = '0';
				put_pixel(engine, engine->element->ground, engine->monster[m]->y + 1,
					engine->monster[m]->x);
			}
			else
				trick_case(engine, m);
		}
	}
	return (0);
}

int	get_monster_nb(t_data_engine *engine)
{
	int	y;
	int	x;
	int	m;

	y = -1;
	m= 0;
	while (++y < engine->map->line)
	{
		x = -1;
		while (++x < engine->map->column)
		{
			if ((engine)->map->map[y][x] == 'M')
				m++;
		}
	}
	return (m);
}