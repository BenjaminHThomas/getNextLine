/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 14:59:46 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/05 18:29:31 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char *text)
{
	char	*linestr;
	int		linelen;
	int		i;

	linelen = 0;
	while (text[linelen] && text[linelen] != '\n')
		linelen++;
	linestr = (char *)malloc(linelen + 1);
	if (!linestr)
		return (NULL);
	i = -1;
	while (++i <= linelen)
		linestr[i] = text[i];
	linestr[i] = 0;
	return (linestr);
}

static void	append(char	*text, char *buf)
{
	int	len;
	int	i;

	len = 0;
	while (text[len])
		len++;
	i = -1;
	while (buf[++i])
		text[len + i] = buf[i];
	text[len + i] = 0;
	free(buf);
}

static void	read_file(int fd, char *text)
{
	char	*buf;
	int		r;

	buf = NULL;
	while (!buf || !contains_nl(buf))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return ;
		r = read(fd, buf, BUFFER_SIZE);
		if (!r)
		{
			free(buf);
			return ;
		}
		buf[r] = 0;
		append(text, buf);
	}
}

char	*get_next_line(int fd)
{
	static char	text[1 << 12];
	char		*linestr;

	read_file(fd, text);
	linestr = get_line(text);
	clean_text(text);
	return (linestr);
}
