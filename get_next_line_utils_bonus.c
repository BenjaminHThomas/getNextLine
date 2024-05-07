/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:17:49 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/07 10:55:06 by bthomas          ###   ########.fr       */
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

void	ft_bzero(void *p, size_t size)
{
	unsigned char	*a;

	a = p;
	while (size--)
		*a++ = 0;
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

	len = 0;
	while (s[len])
		len++;
	cpy = malloc(len + 1);
	cpy[len] = 0;
	while (len--)
		cpy[len] = s[len];
	return (cpy);
}

void	clean_text(char **text)
{
	char	*temp;
	char	*cleaned;
	int		i;

	if (!*text)
		return ;
	temp = *text;
	while (*temp && *temp != '\n')
		temp++;
	if (*temp == '\n')
		temp++;
	cleaned = ft_strdup(temp);
	if (cleaned)
	{
		i = -1;
		while (cleaned[++i])
			(*text)[i] = cleaned[i];
		(*text)[i] = 0;
		free(cleaned);
	}
}
