/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponieck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:26:12 by jponieck          #+#    #+#             */
/*   Updated: 2024/03/10 14:26:15 by jponieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		i;
	char	*result;

	fd = open("test.txt", O_RDONLY);
	i = 0;
	while (1)
	{
		result = get_next_line(fd);
		if (result)
		{
			printf("%s", result);
			// printf("strlen %ld\n", strlen(result));
			free(result);
		}
		else
			break ;
		i++;
		printf("---- ---- ---- ---- \n");
	}
}
