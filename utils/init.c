/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidbaha <lidbaha@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:08:40 by lidbaha           #+#    #+#             */
/*   Updated: 2025/02/07 17:36:49 by lidbaha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core/so_long.h"

void	init(t_vars *vars, t_map *map, char *input)
{
	map->map_name = input;
	vars->win_created = 0;
	vars->map_created = 0;
	vars->img_created = 0;
	vars->error = 0;
	vars->dir = PLAYER_TEXTURE_RIGHT;
	vars->move = 0;
	vars->total_items = 0;
	vars->items = 0;
	vars->end = 0;
	vars->mlx = mlx_init();
	if (!vars->mlx)
	{
		ft_printf("Error\nfailed to init\n");
		exit(1);
	}
}

void	create_window(t_vars *vars)
{
	vars->win_w = ft_strlen(vars->map[0]) * vars->img_w;
	vars->win_h = (map_len(vars)) * vars->img_h;
	vars->win = mlx_new_window(vars->mlx, vars->win_w,
			vars->win_h, WINDOW_NAME);
	if (vars->img)
		mlx_destroy_image(vars->mlx, vars->img);
	vars->win_created = 1;
}
