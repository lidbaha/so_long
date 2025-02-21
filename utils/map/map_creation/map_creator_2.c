/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creator_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidbaha <lidbaha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:01:41 by lidbaha           #+#    #+#             */
/*   Updated: 2025/02/12 14:57:44 by lidbaha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../core/so_long.h"

void	check_image(t_vars *vars)
{
	if (!vars->img)
	{
		vars->error = 1;
		vars->error_type = "Failed to load texture";
		vars->img_created = 0;
		close_window(vars);
	}
}

void	create_map(t_vars *v, t_map	*map, char *texture, int type)
{
	if (type == 0)
	{
		map->img = mlx_xpm_file_to_image(v->mlx, texture,
				&map->img_w, &map->img_h);
		if (!map->img)
		{
			v->error = 1;
			v->error_type = "Failed to load texture";
			close_window(v);
		}
		mlx_put_image_to_window(v->mlx, v->win, map->img, map->x, map->y);
		mlx_destroy_image(v->mlx, map->img);
	}
	else
	{
		v->img = mlx_xpm_file_to_image(v->mlx, v->dir, &v->img_w, &v->img_h);
		check_image(v);
		mlx_put_image_to_window(v->mlx, v->win, v->img, v->x, v->y);
	}
}

void	map_parsing(t_vars *vars, t_map	*map, char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] == '1')
			create_map(vars, map, WALL_TEXTURE, 0);
		if (line[i] == '0')
			create_map(vars, map, GROUND_TEXTURE, 0);
		if (line[i] == 'E')
			create_map(vars, map, EXIT_TEXTURE, 0);
		if (line[i] == 'C')
			create_map(vars, map, ITEM_TEXTURE, 0);
		if (line[i] == 'P')
		{
			vars->x = map->x;
			vars->y = map->y;
			create_map(vars, map, vars->dir, 1);
		}
		map->x += map->img_w;
		i++;
	}
}

void	map_gen(t_vars *vars, t_map *map)
{
	int	i;

	i = 0;
	map->x = 0;
	map->y = 0;
	while (vars->map[i] != NULL)
	{
		map_parsing(vars, map, vars->map[i]);
		map->y += map->img_h;
		map->x = 0;
		i++;
	}
}
