/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_suite_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:43:21 by brhajji-          #+#    #+#             */
/*   Updated: 2022/02/15 14:35:20 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_monster_position(t_data_engine	**engine)
{
	int	y;
	int	x;
	int	m;

	y = -1;
	m = 0;
	while (++y < (*engine)->map->line)
	{
		x = -1;
		while (++x < (*engine)->map->column)
		{
			if ((*engine)->map->map[y][x] == 'M')
			{
				(*engine)->monster[m]->x = x;
				(*engine)->monster[m]->y = y;
				m++;
			}
		}
	}
	return ;
}

void	free_monsters(t_data_engine	*engine)
{
	int	i;

	i = -1;
	while (++i < engine->nb_monster)
		free(engine->monster[i]);
	free(engine->monster);
}

void	free_monsters_img(t_data_engine	*engine)
{
	if (engine->element->monster_b)
		mlx_destroy_image(engine->init->mlx, engine->element->monster_b);
	if (engine->element->monster_l)
		mlx_destroy_image(engine->init->mlx, engine->element->monster_l);
	if (engine->element->monster_lb)
		mlx_destroy_image(engine->init->mlx, engine->element->monster_lb);
	if (engine->element->monster_lt)
		mlx_destroy_image(engine->init->mlx, engine->element->monster_lt);
	if (engine->element->monster_r)
		mlx_destroy_image(engine->init->mlx, engine->element->monster_r);
	if (engine->element->monster_rb)
		mlx_destroy_image(engine->init->mlx, engine->element->monster_rb);
	if (engine->element->monster_rt)
		mlx_destroy_image(engine->init->mlx, engine->element->monster_rt);
	if (engine->element->monster_t)
		mlx_destroy_image(engine->init->mlx, engine->element->monster_t);
	if (engine->monster)
		free_monsters(engine);
}

void	*malloc_monsters(t_data_engine	*engine)
{
	int			x;
	int			i;
	t_monster	**tmp;

	i = 0;
	x = get_monster_nb(engine);
	engine->nb_monster = x;
	tmp = malloc(sizeof(t_monster **));
	if (!tmp)
		return (NULL);
	while (i < x)
	{
		tmp[i] = malloc(sizeof(t_monster));
		if (!tmp[i])
			return (NULL);
		i++;
	}
	return (tmp);
}

int	get_monster_nb(t_data_engine *engine)
{
	int	y;
	int	x;
	int	m;

	y = -1;
	m = 0;
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
