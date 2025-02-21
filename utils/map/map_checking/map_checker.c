/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidbaha <lidbaha@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:21:49 by lidbaha           #+#    #+#             */
/*   Updated: 2025/02/03 14:32:34 by lidbaha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../core/so_long.h"

int	check_item(t_vars *vars)
{
	int	i;
	int	j;

	j = 0;
	while (vars->map[j] != NULL)
	{
		i = 0;
		while (vars->map[j][i] != '\0')
		{
			if (vars->map[j][i] == 'C')
				vars->total_items += 1;
			i++;
		}
		j++;
	}
	if (vars->total_items == 0)
		return (1);
	return (0);
}

int	check_elements(t_vars *vars)
{
	int	i;
	int	j;
	int	p;
	int	e;

	j = 0;
	p = 0;
	e = 0;
	while (vars->map[j] != NULL)
	{
		i = 0;
		while (vars->map[j][i] != '\0')
		{
			if (vars->map[j][i] == 'P')
				p++;
			if (vars->map[j][i] == 'E')
				e++;
			i++;
		}
		j++;
	}
	if (p != 1 || e != 1)
		return (1);
	return (0);
}

void	check_map_2(t_vars *vars)
{
	if (check_elements(vars) == 1)
	{
		vars->error = 1;
		vars->error_type = "Invalid number of elements";
	}
	else if (check_exit(vars) == 1)
	{
		vars->error = 1;
		vars->error_type = "No exit possible";
	}
}

void	check_map(t_vars *vars)
{
	if (check_item(vars) == 1)
	{
		vars->error = 1;
		vars->error_type = "Missing item";
	}
	else if (check_if_rectangle(vars) == 1)
	{
		vars->error = 1;
		vars->error_type = "Map not rectangle";
	}
	else if (check_if_closed(vars) == 1)
	{
		vars->error = 1;
		vars->error_type = "Map not closed";
	}
	else if (check_char(vars) == 1)
	{
		vars->error = 1;
		vars->error_type = "Invalid character";
	}
	else
		check_map_2(vars);
	if (vars->error == 1)
		close_window(vars);
}
