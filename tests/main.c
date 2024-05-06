/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:12:45 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/06 15:42:24 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	int		fd;
	char	*line;
	int		i;

	if (ac != 2)
		return (1);
	fd = open(av[1], O_RDONLY);
	i = -1;
	while (++i < 10)
	{
		line = get_next_line(fd);
		if (line && *line)
		{
			printf("%s", line);
			free(line);
		}
	}
	free(line);
	close(fd);
	return (0);
} 

/* cc main.c ../get_next_line.c ../get_next_line_utils.c */
