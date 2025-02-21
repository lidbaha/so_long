/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidbaha <lidbaha@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 07:47:13 by lidbaha           #+#    #+#             */
/*   Updated: 2025/02/05 09:26:04 by lidbaha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_vars		vars;
	t_map		map;

	if (!(argc < 2 || argc > 2))
	{
		if (check_file_format(argv[1]) == 0)
		{
			init(&vars, &map, argv[1]);
			get_map(&vars, &map);
			check_map(&vars);
			create_window(&vars);
			map_gen(&vars, &map);
			mlx_hook(vars.win, 2, 1L << 0, &key_handler, &vars);
			mlx_hook(vars.win, 17, 1L << 0, &close_window, &vars);
			mlx_loop(vars.mlx);
		}
		else
			ft_printf("Error\nwrong file extension\n");
	}
	else
		ft_printf("Error\nwrong parameters\n");
	return (0);
}
