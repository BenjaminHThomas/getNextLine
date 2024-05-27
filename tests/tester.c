/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:21:09 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/25 11:52:24 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	char	*line;
	int		fd1;
	//int		fd2;
	int		null_check;

	(void)ac;
	fd1 = open(av[1], O_RDONLY);
	null_check = 0;
	while (!null_check)
	{
		line = get_next_line(fd1);
		printf("%s", line);
		if (!line)
			null_check = 1;
		else
			free(line);
	}
	line = NULL;
	/*
	printf("\nTesting second fd...\n");

	fd2 = open(av[2], O_RDONLY);
	null_check = 0;
	while (!null_check)
	{
		line = get_next_line(fd2);
		printf("%s", line);
		if (!line)
			null_check = 1;
		else
			free(line);
	}
	*/
	return (0);
}
