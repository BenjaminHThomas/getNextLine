/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:28:09 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/02 14:58:22 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		in(char *s, int i)
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
		if (s[i] == '\n')
		{
			linenum--;
			if (linenum)
				prev_pos = i;
		}
	}
	len = i - prev_pos;
	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	i = -1;
	while (++prev_pos < len)
		word[++i] = s[prev_pos];
	word[len] = 0;
	return (word);
}
