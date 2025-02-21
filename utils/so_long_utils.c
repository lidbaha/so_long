/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidbaha <lidbaha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:52:58 by lidbaha           #+#    #+#             */
/*   Updated: 2025/02/12 14:55:51 by lidbaha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core/so_long.h"

void	check_key(t_vars *vars, int keycode)
{
	if (keycode == 'w' || keycode == 65362)
	{
		vars->y -= vars->img_h;
		vars->dir = PLAYER_TEXTURE_UP;
		draw(vars, keycode);
	}
	if (keycode == 's' || keycode == 65364)
	{
		vars->y += vars->img_h;
		vars->dir = PLAYER_TEXTURE_DOWN;
		draw(vars, keycode);
	}
	if (keycode == 'd' || keycode == 65363)
	{
		vars->x += vars->img_h;
		vars->dir = PLAYER_TEXTURE_RIGHT;
		draw(vars, keycode);
	}
	if (keycode == 'a' || keycode == 65361)
	{
		vars->x -= vars->img_h;
		vars->dir = PLAYER_TEXTURE_LEFT;
		draw(vars, keycode);
	}
}

void	free_all(t_vars *vars)
{
	int	i;

	if (vars->img_created == 1)
		mlx_destroy_image(vars->mlx, vars->img);
	if (vars->win_created == 1)
		mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	if (vars->map_created == 1)
	{
		i = 0;
		while (vars->map[i])
		{
			free(vars->map[i]);
			i++;
		}
		free(vars->map);
	}
	free(vars->mlx);
}

int	close_window(t_vars *vars)
{
	if (vars->error == 1)
		ft_printf("Error\n%s\n", vars->error_type);
	free_all(vars);
	exit(1);
	return (0);
}

int	key_handler(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		close_window(vars);
	else
		if (vars->end == 0)
			check_key(vars, keycode);
	return (0);
}

int	check_file_format(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
		{
			j = 1;
			if (str[i + 1] != 'b' || str[i + 2] != 'e' || str[i + 3] != 'r')
				return (1);
		}
		i++;
	}
	if (j == 0)
		return (1);
	return (0);
}
