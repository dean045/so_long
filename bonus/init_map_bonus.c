/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 12:26:52 by brhajji-          #+#    #+#             */
/*   Updated: 2022/02/16 15:22:33 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	get_nb_lines(char *file)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd, 10);
	if (!line)
		return (0);
	while (line != NULL)
	{
		i++;
		free(line);
		line = get_next_line(fd, 10);
	}
	return (i);
}

char	**init_map(char *file, int size)
{
	char	**map;
	int		i;
	int		fd;

	i = 0;
	size = get_nb_lines(file);
	map = malloc(sizeof(char *) * (size + 1));
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (i <= size)
	{
		map[i] = get_next_line(fd, 10);
		i++;
	}
	return (map);
}

void	free_map(t_data_engine	*engine)
{
	int	i;

	i = 0;
	while (i < engine->map->line)
	{
		free(engine->map->map[i]);
		i++;
	}
	free(engine->map->map);
	free(engine->map);
}

int	litle_free(t_data_engine	*engine)
{
	if (engine->monster)
		free_monsters(engine);
	if (engine->img)
		free_img(engine);
	if (engine->element)
		free(engine->element);
	if (engine->init)
		free(engine->init);
	if (engine->map)
		free_map(engine);
	if (engine->player)
		free(engine->player);
	free(engine);
	return (0);
}

void	set_element_on_display(t_data_engine	*engine)
{
	int	y;
	int	x;
	int	m;

	y = -1;
	m = -1;
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
				put_pixel(engine, select_monster_face(engine, engine->monster
					[++m]), y, x);
		}
	}
}
