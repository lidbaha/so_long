/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidbaha <lidbaha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:44:37 by lidbaha           #+#    #+#             */
/*   Updated: 2025/02/12 14:56:40 by lidbaha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/get_next_line/get_next_line.h"
#include "../includes/ft_printf/ft_printf.h"
#include "../includes/minilib/mlx_int.h"
#include "../includes/minilib/mlx.h"
#include "../includes/libft/libft.h"

#define WINDOW_NAME "so_long"
#define WALL_TEXTURE "./textures/wall.xpm"
#define ITEM_TEXTURE "./textures/fish.xpm"
#define EXIT_TEXTURE "./textures/exit.xpm"
#define GROUND_TEXTURE "./textures/ground.xpm"
#define PLAYER_TEXTURE_RIGHT "./textures/player_right.xpm"
#define PLAYER_TEXTURE_UP "./textures/player_up.xpm"
#define PLAYER_TEXTURE_DOWN "./textures/player_down.xpm"
#define PLAYER_TEXTURE_LEFT "./textures/player_left.xpm"

/* Textures credit: TheRealFusion, https://jitsukoan.itch.io/little-pingu */

typedef struct s_vars
{
	t_win_list	*win;
	t_xvar		*mlx;
	int			x;
	int			y;
	void		*img;
	int			img_w;
	int			img_h;
	int			win_w;
	int			win_h;
	char		*dir;
	int			error;
	char		*error_type;
	char		**map;
	int			win_created;
	int			map_created;
	int			img_created;
	int			move;
	int			total_items;
	int			items;
	int			end;
}				t_vars;

typedef struct s_map
{
	int		x;
	int		y;
	void	*img;
	int		img_w;
	int		img_h;
	char	*map_name;
	int		map_fd;
}				t_map;

void	init(t_vars *vars, t_map *map, char *input);
int		key_handler(int keycode, t_vars *vars);
void	get_map(t_vars *vars, t_map	*map);
void	map_gen(t_vars *vars, t_map *map);
void	draw(t_vars *vars, int keycode);
int		check_if_rectangle(t_vars *vars);
int		check_if_closed(t_vars *vars);
int		check_file_format(char *str);
void	create_window(t_vars *vars);
int		close_window(t_vars *vars);
void	check_image(t_vars *vars);
int		check_exit(t_vars *vars);
int		check_char(t_vars *vars);
void	check_map(t_vars *vars);
int		map_len(t_vars *vars);