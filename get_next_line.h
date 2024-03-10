/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <jponieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 22:33:25 by jponieck          #+#    #+#             */
/*   Updated: 2024/03/05 18:06:02 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# include <stdio.h>
# include <string.h>

typedef struct bfr
{
	char	content[BUFFER_SIZE];
	char	*position;
	char	*end;
}	t_buffer;

char	*get_next_line(int fd);
int		search_n(t_buffer *b);
int		re_malloc(char **line, t_buffer *b);
char	*add_2_line(char *line, t_buffer *b, int *mode);
int		gnl_bzero(char *src, int size, int mode);
int		init_values(int *mode, int *init, t_buffer *b);

#endif
