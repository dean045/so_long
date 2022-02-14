/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:09:43 by brhajji-          #+#    #+#             */
/*   Updated: 2022/02/14 14:05:50 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include<stdlib.h>
# include <time.h>
# include <sys/time.h>
# include<unistd.h>
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "get_next_line.h"

# define WALL "assets/wall.xpm"
# define GROUND "assets/ground.xpm"
# define PLAYER "assets/brams_png.xpm"
# define COIN "assets/money.xpm"
# define DOOR_OPEN "assets/door_open.xpm"
# define DOOR_CLOSE "assets/door_close.xpm"
# define MONSTER_T "assets/zemour_t.xpm"
# define MONSTER_RT "assets/zemour_rt.xpm"
# define MONSTER_LT "assets/zemour_lt.xpm"
# define MONSTER_B "assets/zemour_b.xpm"
# define MONSTER_RB "assets/zemour_rb.xpm"
# define MONSTER_LB "assets/zemour_lb.xpm"
# define MONSTER_R "assets/zemour_r.xpm"
# define MONSTER_L "assets/zemour_l.xpm"
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64

typedef struct s_element
{	
	int		color;
	void	*wall;
	void	*ground;
	void	*player;
	void	*coin;
	void	*close_door;
	void	*open_door;
	void	*monster_rt;
	void	*monster_lt;
	void	*monster_r;
	void	*monster_l;
	void	*monster_lb;
	void	*monster_rb;
	void	*monster_t;
	void	*monster_b;
	int		width;
	int		height;
}	t_element;

typedef struct s_data_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_l;
	int		endian;
}				t_data_img;

typedef struct s_map
{
	char	**map;
	int		line;
	int		column;
}				t_map;
typedef struct s_init
{
	void	*mlx;
	void	*window;
}			t_init;

typedef struct s_player
{
	int	x;
	int	y;
	int	coins;
	int	max_coins;
}			t_player;

typedef struct s_monster
{
	int	x;
	int	y;
}			t_monster;

typedef struct s_data_engine
{
	t_data_img		*img;
	t_data_img		*tmp;
	t_element		*element;
	t_init			*init;
	t_map			*map;
	t_player		*player;
	t_monster		**monster;
	struct timeval	tv;
	int				nb_monster;
	int				nb_coup;
}				t_data_engine;

char			**init_map(char *file, int size);
int				check_map(char **map, int l);
int				get_nb_lines(char *file);
int				insert_sprite(t_data_engine *engine);
unsigned int	get_color_pixel(t_data_engine *engine, void *img, int y, int x);
void			my_mlx_pixel_put(t_data_engine *data, int x, int y, int color);
void			put_pixel(t_data_engine *engine, void *img, int y, int x);
void			display_map(t_data_engine	*engine);
int				key_hook(int keycode, t_data_engine	*engine);
int				game_over(t_data_engine	*engine);
int				check_files(char *map);
void			free_map(t_data_engine	*engine);
void			free_element(t_data_engine *engine);
void			free_img(t_data_engine *engine);
void			up_coins(t_data_engine *engine);
void			ft_putnbr_fd(long n, int fd);
void			set_monster_position(t_data_engine	**engine);
void			*select_monster_face(t_data_engine	*engine, t_monster *monster);
int				animate_monster(t_data_engine *engine);
void			refresh_face(t_data_engine *engine);
int				check_monster_pos(int x, int y, t_data_engine *engine);
int				get_monster_nb(t_data_engine *engine);
void			*malloc_monsters(t_data_engine	*engine);
void			free_monsters_img(t_data_engine	*engine);
#endif