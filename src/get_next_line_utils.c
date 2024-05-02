/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:28:09 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/02 16:39:52 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	in(char *s, int i)
{
	while (*s)
	{
		if (*s == i)
			return (1);
		s++;
	}
	return (0);
}

char	*get_substr(const char *s, int linenum)
{
	char	*word;
	int		i;
	int		prev_pos;
	int		len;

	i = -1;
	prev_pos = 0;
	while (s[++i] && linenum)
	{
		if (in("\n\r", s[i]))
		{
			linenum--;
			if (linenum)
				prev_pos = i;
		}
	}
	len = i - prev_pos - 1;
	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	i = -1;
	while (++i < len)
		word[i] = s[prev_pos + i];
	word[len] = 0;
	return (word);
}
