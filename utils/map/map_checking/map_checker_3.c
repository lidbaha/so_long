/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidbaha <lidbaha@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:05:41 by lidbaha           #+#    #+#             */
/*   Updated: 2025/02/05 07:14:30 by lidbaha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../core/so_long.h"

void	get_pos(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (vars->map[y] != NULL)
	{
		x = 0;
		while (vars->map[y][x] != '\0')
		{
			if (vars->map[y][x] == 'P')
			{
				vars->x = x;
				vars->y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	fill(t_vars *vars, char **temp, int x, int y)
{
	if (y < 0 || y >= map_len(vars) || x < 0
		|| x >= (int)ft_strlen(vars->map[0]) || (temp[y][x] != '0'
		&& temp[y][x] != 'C' && temp[y][x] != 'P' && temp[y][x] != 'E'))
		return ;
	temp[y][x] = '$';
	fill(vars, temp, x - 1, y);
	fill(vars, temp, x + 1, y);
	fill(vars, temp, x, y - 1);
	fill(vars, temp, x, y + 1);
}

int	check_fill(char **temp)
{
	int	i;
	int	j;

	j = 0;
	while (temp[j] != NULL)
	{
		i = 0;
		while (temp[j][i] != '\0')
		{
			if (temp[j][i] == 'E' || temp[j][i] == 'C')
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

void	free_temp(char **tab, int y)
{
	while (y >= 0)
	{
		free(tab[y]);
		y--;
	}
	free(tab);
}

int	check_exit(t_vars *vars)
{
	int		j;
	char	**temp;

	j = 0;
	temp = malloc(sizeof(char *) * (map_len(vars) + 1));
	if (!temp)
		return (1);
	while (vars->map[j] != NULL)
	{
		temp[j] = ft_strdup(vars->map[j]);
		if (!temp[j])
			return (free_temp(temp, j - 1), 1);
		j++;
	}
	temp[j] = NULL;
	get_pos(vars);
	fill(vars, temp, vars->x, vars->y);
	if (check_fill(temp) == 1)
	{
		free_temp(temp, map_len(vars) - 1);
		return (1);
	}
	free_temp(temp, map_len(vars) - 1);
	return (0);
}
