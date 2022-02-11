/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:53:43 by brhajji-          #+#    #+#             */
/*   Updated: 2022/02/10 14:27:57 by brhajji-         ###   ########.fr       */
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
	engine->element->monster_rt = mlx_xpm_file_to_image(engine->init->mlx,
			MONSTER_RT, &engine->element->width, &engine->element->height);
	engine->element->monster_t = mlx_xpm_file_to_image(engine->init->mlx,
			MONSTER_T, &engine->element->width, &engine->element->height);
	engine->element->monster_lt = mlx_xpm_file_to_image(engine->init->mlx,
			MONSTER_LT, &engine->element->width, &engine->element->height);
	engine->element->monster_l = mlx_xpm_file_to_image(engine->init->mlx,
			MONSTER_L, &engine->element->width, &engine->element->height);
	engine->element->monster_r = mlx_xpm_file_to_image(engine->init->mlx,
			MONSTER_R, &engine->element->width, &engine->element->height);
	engine->element->monster_lb = mlx_xpm_file_to_image(engine->init->mlx,
			MONSTER_LB, &engine->element->width, &engine->element->height);
	engine->element->monster_b = mlx_xpm_file_to_image(engine->init->mlx,
			MONSTER_B, &engine->element->width, &engine->element->height);
	engine->element->monster_rb = mlx_xpm_file_to_image(engine->init->mlx,
			MONSTER_RB, &engine->element->width, &engine->element->height);
	if (!engine->element->close_door || !engine->element->open_door)
		return (0);
	return (1);
}

void	free_element(t_data_engine *engine)
{
	mlx_destroy_image(engine->init->mlx, engine->element->wall);
	mlx_destroy_image(engine->init->mlx, engine->element->ground);
	mlx_destroy_image(engine->init->mlx, engine->element->player);
	mlx_destroy_image(engine->init->mlx, engine->element->coin);
	mlx_destroy_image(engine->init->mlx, engine->element->close_door);
	mlx_destroy_image(engine->init->mlx, engine->element->open_door);
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
