/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_monster_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:26:46 by brhajji-          #+#    #+#             */
/*   Updated: 2022/02/14 16:37:53 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	trick_case(t_data_engine *engine, int m, int *x)
{
	if (engine->map->map[engine->monster[m]->y + 1][engine->monster[m]->x]
		== '0' || engine->map->map[engine->monster[m]->y + 1]
		[engine->monster[m]->x] == 'P')
	{
		*x = 0;
		engine->monster[m]->y += 1;
		if (engine->monster[m]->y == engine->player->y
			&& engine->monster[m]->x == engine->player->x)
		{
			engine->player->alive = 0;
			mlx_loop_end(engine->init->mlx);
			return ;
		}
		engine->map->map[engine->monster[m]->y][engine->monster[m]->x] = 'M';
		engine->map->map[engine->monster[m]->y - 1]
		[engine->monster[m]->x] = '0';
		put_pixel(engine, engine->element->ground, engine->monster[m]->y - 1,
			engine->monster[m]->x);
	}
	else
		*x = 1;
}

void	refresh_face(t_data_engine *engine)
{
	int	m;

	m = -1;
	while (++m < engine->nb_monster)
	{
		put_pixel(engine, engine->element->ground, engine->monster[m]->y,
			engine->monster[m]->x);
		put_pixel(engine, select_monster_face(engine, engine->monster[m]),
			engine->monster[m]->y, engine->monster[m]->x);
	}
}

int	check_monster_pos(int x, int y, t_data_engine *engine)
{
	int	m;

	m = -1;
	while (++m < engine->nb_monster)
	{
		if (x == engine->monster[m]->x && y == engine->monster[m]->y)
			return (1);
	}
	return (0);
}

int	animate_2(t_data_engine *engine, int m)
{
	int				x;

	x = 1;
	gettimeofday(&(engine->tv), NULL);
	if ((engine->map->map[engine->monster[m]->y - 1]
			[engine->monster[m]->x] == '0' || engine->map->map
			[engine->monster[m]->y - 1][engine->monster[m]->x]
		== 'P') && x)
	{
		engine->monster[m]->y -= 1;
		if (engine->monster[m]->y == engine->player->y
			&& engine->monster[m]->x == engine->player->x)
		{
			mlx_loop_end(engine->init->mlx);
			return (0);
		}
		engine->map->map[engine->monster[m]->y]
		[engine->monster[m]->x] = 'M';
		engine->map->map[engine->monster[m]->y + 1]
		[engine->monster[m]->x] = '0';
		put_pixel(engine, engine->element->ground,
			engine->monster[m]->y + 1, engine->monster[m]->x);
	}
	else
		trick_case(engine, m, &x);
	return (1);
}

int	animate_monster(t_data_engine *engine)
{
	int				m;
	struct timeval	tv2;

	gettimeofday(&(tv2), NULL);
	if (tv2.tv_sec == engine->tv.tv_sec + 1)
	{
		m = -1;
		while (++m < engine->nb_monster)
		{
			if (!animate_2(engine, m))
				return (0);
			if (engine->player->alive == 1)
			{
				put_pixel(engine, select_monster_face(engine, engine->monster
					[m]), engine->monster[m]->y, engine->monster[m]->x);
				mlx_put_image_to_window(engine->init->mlx, engine->init->window,
					engine->img->img, 0, 0);
			}
		}
	}
	return (0);
}
