/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidbaha <lidbaha@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:48:35 by lidbaha           #+#    #+#             */
/*   Updated: 2025/01/31 16:59:37 by lidbaha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../core/so_long.h"

int	check_if_closed_line(t_vars *vars, int j)
{
	int	i;

	i = 0;
	while (vars->map[j][i] != '\0')
	{
		if (vars->map[j][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_if_closed_col(t_vars *vars, int i)
{
	int	j;

	j = 0;
	while (vars->map[j] != NULL)
	{
		if (vars->map[j][i] != '1')
			return (1);
		j++;
	}
	return (0);
}

int	check_if_closed(t_vars *vars)
{
	if (check_if_closed_line(vars, 0) == 1)
		return (1);
	if (check_if_closed_line(vars, map_len(vars) - 1) == 1)
		return (1);
	if (check_if_closed_col(vars, 0) == 1)
		return (1);
	if (check_if_closed_col(vars, ft_strlen(vars->map[0]) - 1) == 1)
		return (1);
	return (0);
}

int	check_if_rectangle(t_vars *vars)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(vars->map[i]);
	while (vars->map[i] != NULL)
	{
		if ((int)ft_strlen(vars->map[i]) != len)
			return (1);
		i++;
	}
	return (0);
}

int	check_char(t_vars *vars)
{
	int	i;
	int	j;

	j = 0;
	while (vars->map[j] != NULL)
	{
		i = 0;
		while (vars->map[j][i] != '\0')
		{
			if (vars->map[j][i] != '1' && vars->map[j][i] != '0'
				&& vars->map[j][i] != 'P' && vars->map[j][i] != 'C'
					&& vars->map[j][i] != 'E')
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}
