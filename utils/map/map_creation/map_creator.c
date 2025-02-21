/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidbaha <lidbaha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:55:39 by lidbaha           #+#    #+#             */
/*   Updated: 2025/02/12 14:52:31 by lidbaha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../core/so_long.h"

int	check_no_double_newline(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\n')
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static int	join_and_split(t_vars *vars, t_map *map, char *buff, char *line)
{
	char	*temp;

	while (line)
	{
		temp = buff;
		buff = ft_strjoin(buff, line);
		free(temp);
		if (!buff)
		{
			free(line);
			vars->error_type = "malloc error";
			return (1);
		}
		free(line);
		line = get_next_line(map->map_fd);
	}
	if (check_no_double_newline(buff) == 1)
		return (vars->error_type = "empty line in the map", 1);
	vars->map = ft_split(buff, '\n');
	free(buff);
	free(line);
	if (!vars->map)
		return (vars->error_type = "malloc error", 1);
	return (0);
}

int	read_map(t_vars *vars, t_map *map)
{
	char	*line_map;
	char	*buff;

	buff = ft_strdup("");
	if (!buff)
	{
		vars->error_type = "malloc error";
		return (1);
	}
	line_map = get_next_line(map->map_fd);
	if (!line_map)
	{
		free(buff);
		vars->error_type = "file empty";
		return (1);
	}
	return (join_and_split(vars, map, buff, line_map));
}

void	get_map(t_vars *vars, t_map	*map)
{
	map->map_fd = open(map->map_name, O_RDONLY);
	if (map->map_fd == -1)
	{
		vars->error = 1;
		vars->error_type = "Unable to open file";
		close(map->map_fd);
		close_window(vars);
	}
	vars->img = mlx_xpm_file_to_image(vars->mlx, vars->dir,
			&vars->img_w, &vars->img_h);
	check_image(vars);
	vars->img_created = 1;
	if (read_map(vars, map) == 1)
	{
		vars->error = 1;
		close(map->map_fd);
		close_window(vars);
	}
	close(map->map_fd);
	vars->map_created = 1;
}

int	map_len(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map[i] != NULL)
		i++;
	return (i);
}
