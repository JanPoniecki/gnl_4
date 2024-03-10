/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 22:33:08 by jponieck          #+#    #+#             */
/*   Updated: 2024/03/05 17:29:42 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_bzero(char *src, int size, int mode)
{
	int	i;

	i = 0;
	if (mode == 0)
	{
		while (i < size)
			src[i++] = 0;
	}
	else
	{
		while (src[i])
			i++;
	}
	return (i);
}

int	init_values(int *mode, int *init, t_buffer *b)
{
	*mode = 0;
	b->end = &(b->content[BUFFER_SIZE]);
	*(b->end) = 0;
	if (*init == 0)
	{
		b->position = b->end;
		*init = 1;
	}
	if (*init == 2)
		return (0);
	return (1);
}

int	search_n(t_buffer *b)
{
	int	i;

	i = 0;
	while (b->position[i] != '\n' && b->position[i])
		i++;
	return (i);
}

int	re_malloc(char **line, t_buffer *b)
{
	int		i;
	char	*temp;

	i = 0;
	while ((*line)[i])
		i++;
	temp = malloc(i + 1);
	i = 0;
	while ((*line)[i])
	{
		temp[i] = (*line)[i];
		i++;
	}
	temp[i] = 0;
	(*line) = malloc(i + search_n(b) + 2);
	i = 0;
	while (temp[i])
	{
		(*line)[i] = temp[i];
		i++;
	}
	free(temp);
	return (i);
}

char	*add_2_line(char *line, t_buffer *b, int *mode)
{
	int	i;

	i = re_malloc(&line, b);
	while (1)
	{
		line[i] = *b->position;
		if (line[i] == '\n')
		{
			line[i + 1] = 0;
			*mode = 1;
			if (b->position != b->end)
				b->position++;
			return (line);
		}
		if (b->position == b->end)
		{
			line[i] = 0;
			*mode = 2;
			return (line);
		}
		b->position++;
		i++;
	}
	return (NULL);
}
