/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 14:59:46 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/05 19:08:09 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char *text)
{
	char	*linestr;
	int		linelen;
	int		i;

	if (!text)
		return (NULL);
	linelen = 0;
	while (text[linelen] && text[linelen] != '\n')
		linelen++;
	linestr = (char *)malloc(linelen + 1);
	if (!linestr)
		return (NULL);
	ft_bzero(linestr, linelen + 1);
	i = -1;
	while (++i <= linelen)
		linestr[i] = text[i];
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
	int		nl_bool;

	nl_bool = 0;
	while (nl_bool == 0)
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return ;
		ft_bzero(buf, BUFFER_SIZE + 1);
		r = read(fd, buf, BUFFER_SIZE);
		if (!r)
		{
			free(buf);
			return ;
		}
		nl_bool = contains_nl(buf);
		buf[r] = 0;
		append(text, buf);
	}
}

char	*get_next_line(int fd)
{
	static char	text[1 << 12];
	char		*linestr;

	read_file(fd, text);
	if (!text[0])
		return (NULL);
	linestr = get_line(text);
	clean_text(text);
	return (linestr);
}
