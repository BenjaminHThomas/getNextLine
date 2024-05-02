/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:40:00 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/02 16:05:15 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	int		fd;
	char	*ret;

	if (ac < 1)
		return (1);
	fd = open(av[1], O_RDONLY);
	ret = get_next_line(fd);
	printf("%s", ret);
	free(ret);
	return (0);
}
