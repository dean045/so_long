/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sprite_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:53:43 by brhajji-          #+#    #+#             */
/*   Updated: 2022/02/14 16:04:13 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	insert_tex_part2(t_data_engine *engine)
{
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
}

int	insert_tex(t_data_engine *engine)
{
	engine->element->wall = mlx_xpm_file_to_image(engine->init->mlx, WALL,
			&engine->element->width, &engine->element->height);
	engine->element->ground = mlx_xpm_file_to_image(engine->init->mlx, GROUND,
			&engine->element->width, &engine->element->height);
	engine->element->player = mlx_xpm_file_to_image(engine->init->mlx, PLAYER,
			&engine->element->width, &engine->element->height);
	engine->element->coin = mlx_xpm_file_to_image(engine->init->mlx, COIN,
			&engine->element->width, &engine->element->height);
	engine->element->close_door = mlx_xpm_file_to_image(engine->init->mlx,
			DOOR_CLOSE, &engine->element->width, &engine->element->height);
	engine->element->open_door = mlx_xpm_file_to_image(engine->init->mlx,
			DOOR_OPEN, &engine->element->width, &engine->element->height);
	insert_tex_part2(engine);
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
	free_monsters_img(engine);
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
