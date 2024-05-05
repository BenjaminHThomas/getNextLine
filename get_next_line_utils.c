/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:17:49 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/05 18:24:12 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	contains_nl(char *s)
{
	int	i;

	if (NULL == s)
		return (0);
	i = -1;
	while (s[++i])
		if (s[i] == '\n')
			return (1);
	return (0);
}

char	*ft_strdup(const char *s)
{
	int		len;
	char	*cpy;

	len = 0;
	while (s[len])
		len++;
	cpy = malloc(len + 1 * sizeof(char));
	cpy[len] = 0;
	while (len--)
		cpy[len] = s[len];
	return (cpy);
}

void	clean_text(char *text)
{
	char	*temp;
	char	*cleaned;
	int		i;

	temp = text;
	while (*temp && *temp != '\n')
		temp++;
	if (*temp == '\n')
		temp++;
	cleaned = ft_strdup(temp);
	if (cleaned)
	{
		i = -1;
		while (cleaned[++i])
			text[i] = cleaned[i];
		text[i] = 0;
		free(cleaned);
	}
}
