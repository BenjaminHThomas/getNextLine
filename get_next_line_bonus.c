/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 14:59:46 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/22 22:42:38 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*get_line(char **text)
{
	char	*linestr;
	int		linelen;
	int		i;

	if (!*text || !*(*text))
		return (NULL);
	linelen = 0;
	while ((*text)[linelen] && (*text)[linelen] != '\n')
		linelen++;
	linestr = (char *)ft_calloc(linelen + 2);
	if (!linestr)
		return (NULL);
	i = -1;
	while (++i <= linelen)
		linestr[i] = (*text)[i];
	return (linestr);
}

static void	append(char **text, char *buf)
{
	char	*temp;
	int		len;
	int		i;

	if (!buf || !*buf)
		return ;
	len = ft_strlen(*text) + ft_strlen(buf);
	if (!len)
		return ;
	temp = *text;
	*text = (char *)ft_calloc(len + 1);
	if (!*text)
	{
		free(temp);
		return ;
	}
	len = -1;
	while (++len >= 0 && temp && temp[len])
		(*text)[len] = temp[len];
	i = -1;
	while (buf[++i])
		(*text)[len + i] = buf[i];
	free(temp);
}

static void	read_file(int fd, char **text)
{
	char	*buf;
	int		r;
	int		nl_bool;

	nl_bool = 0;
	while (nl_bool == 0)
	{
		buf = (char *)ft_calloc(BUFFER_SIZE + 1);
		if (!buf)
			return ;
		r = read(fd, buf, BUFFER_SIZE);
		if (r <= 0)
		{
			free(buf);
			return ;
		}
		nl_bool = contains_nl(buf);
		append(text, buf);
		free(buf);
	}
}

char	*get_next_line(int fd)
{
	static char	*list[1 << 10];
	char		*linestr;

	linestr = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0
		|| read(fd, list[0], 0) < 0
		|| fd > (1 << 10))
		return (linestr);
	read_file(fd, &list[fd]);
	linestr = get_line(&list[fd]);
	clean_text(&list[fd]);
	return (linestr);
}
