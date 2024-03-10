/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 21:08:46 by jponieck          #+#    #+#             */
/*   Updated: 2024/03/05 18:10:04 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_buffer	b;
	static int		init;
	int				mode;
	char			*line;

	line = "";
	if (init_values(&mode, &init, &b) == 0)
		return (NULL);
	while (1)
	{
		if (b.position == b.end)
		{
			gnl_bzero(b.content, BUFFER_SIZE, 0);
			if (read(fd, b.content, BUFFER_SIZE) <= 0)
			{
				init = 2;
				if (gnl_bzero(line, 0, 1) == 0)
					return (NULL);
				return (line);
			}
			b.position = &b.content[0];
		}
		line = add_2_line(line, &b, &mode);
		if (mode == 1)
			return (line);
	}
}
