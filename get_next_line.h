/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 14:59:08 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/22 20:13:05 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <stdlib.h>

int		contains_nl(char *s);
char	*get_next_line(int fd);
void	clean_text(char **text);
void	ft_bzero(void *p, size_t size);
int		ft_strlen(char *s);
void	*ft_calloc(size_t size);
char	*ft_strdup(const char *s);

#endif
