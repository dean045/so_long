/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 12:15:45 by brhajji-          #+#    #+#             */
/*   Updated: 2022/02/16 16:05:56 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	err_print(int x)
{	
	if (x != 0)
	{
		write(1, "Error\n", 6);
		if (x == 1)
			write(1, "The map is not closed.\n", 24);
		else if (x == 2)
			write(1, "the map is not square.\n", 24);
		else if (x == 3)
			write(1, "Invalid number of player or dors.\n", 35);
		else if (x == 4)
			write(1, "Unknown element on the map.\n", 29);
		else if (x == 5)
			write(1, "Wrong input.\n", 13);
		else if (x == 99)
			write(1, "Empty map.\n", 12);
		else if (x > 9)
			write(1, "Missing file(s).\n", 18);
		return (1);
	}
	return (0);
}

void	init(t_data_engine	**engine, char *map)
{
	(*engine) = malloc(sizeof(t_data_engine));
	(*engine)->element = malloc(sizeof(t_element));
	(*engine)->img = malloc(sizeof(t_data_img));
	(*engine)->init = malloc(sizeof(t_init));
	(*engine)->map = malloc(sizeof(t_map));
	(*engine)->tmp = malloc(sizeof(t_data_img));
	(*engine)->player = malloc(sizeof(t_player));
	(*engine)->map->line = get_nb_lines(map);
	(*engine)->map->map = init_map(map, (*engine)->map->line);
	(*engine)->map->column = ft_strlen((*engine)->map->map[0]);
	(*engine)->map->column -= 1;
	(*engine)->nb_coup = 0;
}

void	set_player_position(t_data_engine	**engine)
{
	int	y;
	int	x;

	y = -1;
	(*engine)->player->max_coins = 0;
	(*engine)->player->coins = 0;
	while (++y < (*engine)->map->line)
	{
		x = -1;
		while (++x < (*engine)->map->column)
		{
			if ((*engine)->map->map[y][x] == 'P')
			{
				(*engine)->player->x = x;
				(*engine)->player->y = y;
			}
			if ((*engine)->map->map[y][x] == 'C')
				(*engine)->player->max_coins += 1;
		}
	}
	return ;
}

int	game_over(t_data_engine	*engine)
{
	if (engine->img && engine->img->img)
		mlx_destroy_image(engine->init->mlx, engine->img->img);
	if (engine->element)
		free_element(engine);
	if (engine->img)
		free_img(engine);
	if (engine->init->window)
	{
		mlx_clear_window(engine->init->mlx, engine->init->window);
		mlx_destroy_window(engine->init->mlx, engine->init->window);
	}
	if (engine->init->mlx)
	{
		mlx_destroy_display(engine->init->mlx);
		free(engine->init->mlx);
	}
	if (engine->init)
		free(engine->init);
	if (engine->map)
		free_map(engine);
	if (engine->player)
		free(engine->player);
	free(engine);
	return (0);
}

int	main(int ac, char **av)
{
	t_data_engine	*engine;

	if (ac == 2)
	{
		if (err_print(check_files(av[1])))
			return (0);
		init(&engine, av[1]);
		if (!err_print(check_map(engine->map->map, engine->map->line)))
		{
			set_player_position(&engine);
			display_map(engine);
		}
		if (check_map(engine->map->map, engine->map->line))
			return (litle_free(engine));
		mlx_put_image_to_window(engine->init->mlx, engine->init->window,
			engine->img->img, 0, 0);
		mlx_key_hook(engine->init->window, key_hook, engine);
		mlx_hook(engine->init->window, 17, 0, mlx_loop_end, engine->init->mlx);
		mlx_loop(engine->init->mlx);
		game_over(engine);
	}
	else
		err_print(5);
	return (0);
}
