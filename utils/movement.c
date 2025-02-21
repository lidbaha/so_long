/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidbaha <lidbaha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:13:02 by lidbaha           #+#    #+#             */
/*   Updated: 2025/02/12 14:47:15 by lidbaha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core/so_long.h"

int	exit_check(t_vars *vars)
{
	if (vars->items == vars->total_items)
	{
		mlx_clear_window(vars->mlx, vars->win);
		mlx_string_put(vars->mlx, vars->win, vars->win_w / 2,
			vars->win_h / 2, 0xFFFFFF, "END");
		vars->end = 1;
		return (0);
	}
	return (1);
}

int	check_move(t_vars *vars, int keycode)
{
	if (vars->map[vars->y / vars->img_h][vars->x / vars->img_w] == '1')
	{
		if (keycode == 's' || keycode == 65364)
			vars->y -= vars->img_h;
		if (keycode == 'w' || keycode == 65362)
			vars->y += vars->img_h;
		if (keycode == 'd' || keycode == 65363)
			vars->x -= vars->img_w;
		if (keycode == 'a' || keycode == 65361)
			vars->x += vars->img_w;
		return (1);
	}
	if (vars->map[vars->y / vars->img_h][vars->x / vars->img_w] == 'C')
	{
		vars->map[vars->y / vars->img_h][vars->x / vars->img_w] = '0';
		vars->items += 1;
	}
	if (vars->map[vars->y / vars->img_h][vars->x / vars->img_w] == 'E')
	{
		if (!exit_check(vars))
			return (1);
	}
	return (0);
}

char	*prev_texture(t_vars *vars, int keycode)
{
	int	x;
	int	y;

	x = vars->x;
	y = vars->y;
	if (keycode == 's' || keycode == 65364)
		y -= vars->img_h;
	if (keycode == 'w' || keycode == 65362)
		y += vars->img_h;
	if (keycode == 'd' || keycode == 65363)
		x -= vars->img_w;
	if (keycode == 'a' || keycode == 65361)
		x += vars->img_w;
	if (vars->map[y / vars->img_h][x / vars->img_w] == 'E')
		return (EXIT_TEXTURE);
	else
		return (GROUND_TEXTURE);
}

void	replace_prev_img(t_vars *vars, int keycode, char *texture)
{
	mlx_destroy_image(vars->mlx, vars->img);
	vars->img = mlx_xpm_file_to_image(vars->mlx, texture,
			&vars->img_w, &vars->img_h);
	if (keycode == 's' || keycode == 65364)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
			vars->x, (vars->y - vars->img_h));
	}
	if (keycode == 'w' || keycode == 65362)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
			vars->x, (vars->y + vars->img_h));
	}
	if (keycode == 'd' || keycode == 65363)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
			(vars->x - vars->img_w), vars->y);
	}
	if (keycode == 'a' || keycode == 65361)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
			(vars->x + vars->img_w), vars->y);
	}
}

void	draw(t_vars *vars, int keycode)
{
	char	*texture;

	mlx_destroy_image(vars->mlx, vars->img);
	vars->img = mlx_xpm_file_to_image(vars->mlx, vars->dir,
			&vars->img_w, &vars->img_h);
	check_image(vars);
	if (check_move(vars, keycode) == 0)
	{
		vars->move += 1;
		ft_printf("\r%d", vars->move);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
			vars->x, vars->y);
		texture = prev_texture(vars, keycode);
		replace_prev_img(vars, keycode, texture);
	}
}
