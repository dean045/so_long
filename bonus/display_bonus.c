/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:17:02 by brhajji-          #+#    #+#             */
/*   Updated: 2022/02/11 16:51:30 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

unsigned int	get_color_pixel(t_data_engine *engine, void *img, int y, int x)
{
	char	*src;
	int		color;

	engine->tmp->addr = mlx_get_data_addr(img, &engine->tmp->bpp,
			&engine->tmp->line_l, &engine->tmp->endian);
	src = engine->tmp->addr + (y * engine->tmp->line_l + x
			* (engine->tmp->bpp / 8));
	color = *(unsigned int *)src;
	return (color);
}

void	my_mlx_pixel_put(t_data_engine *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img->addr + (y * data->img->line_l + x * (data->img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	put_pixel(t_data_engine *engine, void *img, int y, int x)
{
	int	i;
	int	j;

	i = -1;
	while (++i < TEXTURE_HEIGHT)
	{
		j = -1;
		while (++j < TEXTURE_WIDTH)
		{
			engine->element->color = get_color_pixel(engine, img, i, j);
			if (!(engine->element->color == (0xFF << 24)))
				my_mlx_pixel_put(engine, (x * TEXTURE_WIDTH) + j,
					(y * TEXTURE_WIDTH) + i, engine->element->color);
		}
	}
}

void	*select_monster_face(t_data_engine *engine, t_monster	*monster)
{
	if (engine->player->x == monster->x && engine->player->y > monster->y)
		return (engine->element->monster_b);
	else if (engine->player->x == monster->x && engine->player->y < monster->y)
		return (engine->element->monster_t);
	else if (engine->player->x > monster->x && engine->player->y == monster->y)
		return (engine->element->monster_r);
	else if (engine->player->x < monster->x && engine->player->y == monster->y)
		return (engine->element->monster_l);
	else if (engine->player->x > monster->x && engine->player->y > monster->y)
		return (engine->element->monster_rb);
	else if (engine->player->x > monster->x && engine->player->y < monster->y)
		return (engine->element->monster_rt);
	else if (engine->player->x < monster->x && engine->player->y > monster->y)
		return (engine->element->monster_lb);
	else if (engine->player->x < monster->x && engine->player->y < monster->y)
		return (engine->element->monster_l);
	return (NULL);
}

void	set_element_on_display(t_data_engine	*engine)
{
	int	y;
	int	x;
	int	m;

	y = -1;
	m= -1;
	while (++y < engine->map->line)
	{
		x = -1;
		while (++x < engine->map->column)
		{
			put_pixel(engine, engine->element->ground, y, x);
			if (engine->map->map[y][x] == '1')
				put_pixel(engine, engine->element->wall, y, x);
			if (engine->map->map[y][x] == 'P')
				put_pixel(engine, engine->element->player, y, x);
			if (engine->map->map[y][x] == 'C')
				put_pixel(engine, engine->element->coin, y, x);
			if (engine->map->map[y][x] == 'E')
				put_pixel(engine, engine->element->close_door, y, x);
			if (engine->map->map[y][x] == 'M')
				put_pixel(engine, select_monster_face(engine, engine->monster[++m]), y, x);
		}
	}
}

void	display_map(t_data_engine	*engine)
{
	engine->init->mlx = mlx_init();
	engine->img->img = mlx_new_image(engine->init->mlx, (TEXTURE_WIDTH
				* engine->map->column), (TEXTURE_HEIGHT * engine->map->line));
	engine->img->addr = mlx_get_data_addr(engine->img->img, &engine->img->bpp,
			&engine->img->line_l, &engine->img->endian);
	engine->init->window = mlx_new_window(engine->init->mlx, (TEXTURE_WIDTH
				* engine->map->column), (TEXTURE_HEIGHT * engine->map->line),
			"so_long");
	insert_sprite(engine);
	set_element_on_display(engine);
}
