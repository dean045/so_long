/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:34:44 by brhajji-          #+#    #+#             */
/*   Updated: 2022/02/14 16:03:37 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_x(t_data_engine	*engine, int move)
{
	if (engine->map->map[engine->player->y][engine->player->x + move] == '0' ||
	engine->map->map[engine->player->y][engine->player->x + move] == 'C')
	{
		if (engine->map->map[engine->player->y][engine->player->x + move]
			== 'C')
			up_coins(engine);
		engine->player->x += move;
		engine->map->map[engine->player->y][engine->player->x] = 'P';
		engine->map->map[engine->player->y][engine->player->x - move] = '0';
		engine->nb_coup += 1;
		write(1, "Move(s) = ", 11);
		ft_putnbr_fd(engine->nb_coup, 1);
		write(1, "\n", 1);
		put_pixel(engine, engine->element->player, engine->player->y,
			engine->player->x);
		put_pixel(engine, engine->element->ground, engine->player->y,
			engine->player->x - move);
	}
	else if (engine->map->map[engine->player-> y][engine->player->x + move]
		== 'E' && engine->player->max_coins == engine->player->coins)
		mlx_loop_end(engine->init->mlx);
	else if (check_monster_pos(engine->player->x + move,
			engine->player->y, engine))
		mlx_loop_end(engine->init->mlx);
}

void	move_y(t_data_engine	*engine, int move)
{
	if (engine->map->map[engine->player->y + move][engine->player->x] == '0' ||
	engine->map->map[engine->player->y + move][engine->player->x] == 'C')
	{	
		if (engine->map->map[engine->player->y + move][engine->player->x]
			== 'C')
			up_coins(engine);
		engine->player->y += move;
		engine->map->map[engine->player->y][engine->player->x] = 'P';
		engine->map->map[engine->player->y - move][engine->player->x] = '0';
		engine->nb_coup += 1;
		write(1, "Move(s) = ", 11);
		ft_putnbr_fd(engine->nb_coup, 1);
		write(1, "\n", 1);
		put_pixel(engine, engine->element->player, engine->player->y,
			engine->player->x);
		put_pixel(engine, engine->element->ground, engine->player->y - move,
			engine->player->x);
	}
	else if (engine->map->map[engine->player->y + move][engine->player->x]
		== 'E' && engine->player->max_coins == engine->player->coins)
		mlx_loop_end(engine->init->mlx);
	else if (check_monster_pos(engine->player->x, engine->player->y + move,
			engine))
		mlx_loop_end(engine->init->mlx);
}

void	up_coins(t_data_engine	*engine)
{
	int	x;
	int	y;

	engine->player->coins += 1;
	if (engine->player->coins == engine->player->max_coins)
	{
		y = -1;
		while (++y < engine->map->line)
		{
			x = -1;
			while (++x < engine->map->column)
			{
				if (engine->map->map[y][x] == 'E')
					put_pixel(engine, engine->element->open_door, y, x);
			}
		}
	}
}

int	key_hook(int keycode, t_data_engine	*engine)
{
	if (keycode == 65307)
	{
		mlx_loop_end(engine->init->mlx);
		return (0);
	}
	else if (keycode == 100)
		move_x(engine, 1);
	else if (keycode == 97)
		move_x(engine, -1);
	else if (keycode == 115)
		move_y(engine, 1);
	else if (keycode == 119)
		move_y(engine, -1);
	refresh_face(engine);
	mlx_put_image_to_window(engine->init->mlx, engine->init->window,
		engine->img->img, 0, 0);
	return (0);
}
