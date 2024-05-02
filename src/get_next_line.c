/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:17:05 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/02 15:00:49 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		buf[1 << 12];
	ssize_t		r;
	static int	linenum;

	if (fd < 0)
		return (NULL);
	linenum += 1;
	r = read(fd, buf, sizeof(buf));
	if (r < 0)
		return (NULL);
	return (get_substr(buf, linenum));
}
