/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:53:43 by brhajji-          #+#    #+#             */
/*   Updated: 2022/02/14 16:00:47 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	insert_tex(t_data_engine *engine)
{
	engine->element->wall = mlx_xpm_file_to_image(engine->init->mlx, WALL,
			&engine->element->width, &engine->element->height);
	engine->element->ground = mlx_xpm_file_to_image(engine->init->mlx, GROUND,
			&engine->element->width, &engine->element->height);
	if (!engine->element->wall || !engine->element->ground)
		return (0);
	engine->element->player = mlx_xpm_file_to_image(engine->init->mlx, PLAYER,
			&engine->element->width, &engine->element->height);
	engine->element->coin = mlx_xpm_file_to_image(engine->init->mlx, COIN,
			&engine->element->width, &engine->element->height);
	if (!engine->element->player || !engine->element->coin)
		return (0);
	engine->element->close_door = mlx_xpm_file_to_image(engine->init->mlx,
			DOOR_CLOSE, &engine->element->width, &engine->element->height);
	engine->element->open_door = mlx_xpm_file_to_image(engine->init->mlx,
			DOOR_OPEN, &engine->element->width, &engine->element->height);
	if (!engine->element->close_door || !engine->element->open_door)
		return (0);
	return (1);
}

void	free_element(t_data_engine *engine)
{
	if (engine->element->wall)
		mlx_destroy_image(engine->init->mlx, engine->element->wall);
	if (engine->element->ground)
		mlx_destroy_image(engine->init->mlx, engine->element->ground);
	if (engine->element->player)
		mlx_destroy_image(engine->init->mlx, engine->element->player);
	if (engine->element->coin)
		mlx_destroy_image(engine->init->mlx, engine->element->coin);
	if (engine->element->close_door)
		mlx_destroy_image(engine->init->mlx, engine->element->close_door);
	if (engine->element->open_door)
		mlx_destroy_image(engine->init->mlx, engine->element->open_door);
	if (engine->element)
		free(engine->element);
}

void	free_img(t_data_engine *engine)
{
	if (engine->img)
		free(engine->img);
	if (engine->tmp)
		free(engine->tmp);
}

int	insert_sprite(t_data_engine *engine)
{
	if (!insert_tex(engine))
		return (0);
	return (1);
}
