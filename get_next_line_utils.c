/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:17:49 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/22 22:47:36 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

void	*ft_calloc(size_t size)
{
	unsigned char	*a;
	void			*p;

	p = malloc(size);
	if (!p)
		return (NULL);
	a = p;
	while (size--)
		*a++ = 0;
	return (p);
}

int	contains_nl(char *s)
{
	char	*ps;

	if (!s)
		return (0);
	ps = s;
	while (*ps)
	{
		if (*ps == '\n')
			return (1);
		ps++;
	}
	return (0);
}

char	*ft_strdup(const char *s)
{
	int		len;
	char	*cpy;

	if (!s)
		return (NULL);
	len = ft_strlen((char *)s);
	if (!len)
		return (NULL);
	cpy = malloc((len + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	cpy[len] = 0;
	while (len--)
		cpy[len] = s[len];
	return (cpy);
}

void	clean_text(char **text)
{
	char	*temp;
	char	*cleaned;

	if (!*text)
		return ;
	temp = *text;
	while (*temp && *temp != '\n')
		temp++;
	if (*temp == '\n')
		temp++;
	cleaned = ft_strdup(temp);
	if (!cleaned)
	{
		free(*text);
		*text = NULL;
		return ;
	}
	free(*text);
	*text = cleaned;
}
