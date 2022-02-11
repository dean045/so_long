/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_suite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:43:21 by brhajji-          #+#    #+#             */
/*   Updated: 2022/02/11 18:18:41 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_monster_position(t_data_engine	**engine)
{
	int	y;
	int	x;
	int m;

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

void	*malloc_monsters(t_data_engine	*engine)
{
	int			x;
	int			i;
	t_monster	**tmp;

	i = 0;
	x = get_monster_nb(engine);
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
	tmp[i] = NULL;
	return (tmp);
}