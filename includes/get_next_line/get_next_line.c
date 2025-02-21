/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidbaha <lidbaha@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:50:38 by lidbaha           #+#    #+#             */
/*   Updated: 2025/01/29 09:50:49 by lidbaha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*buffer(char *buff, char *str)
{
	if (check_new_line(buff) == 1)
	{
		remove_line(buff);
		str = ft_strjoin_nl(str, buff);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*result;
	int			r;

	result = NULL;
	r = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	result = buffer(buff, result);
	while (r > 0 && check_new_line(buff) == 0)
	{
		r = read(fd, buff, BUFFER_SIZE);
		if (r < 0)
			return (free(result), NULL);
		if (r == 0 && result != NULL && result[0] != '\0')
			return (result);
		if (r == 0 && !(result != NULL && result[0] != '\0'))
			return (free(result), NULL);
		buff[r] = '\0';
		result = ft_strjoin_nl(result, buff);
		if (result == NULL)
			return (NULL);
	}
	return (result);
}

/*#include <stdio.h>
int	main(void)
{
	char	*result;
	int		fd;
	int		i = 10;

	fd = open("map.ber", O_RDONLY);
	while (i-- > 0)
	{
		result = get_next_line(fd);
		printf("%s", result);
		free(result);
	}
	close(fd);
	return (1);
}*/
