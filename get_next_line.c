/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 04:30:42 by marvin            #+#    #+#             */
/*   Updated: 2024/05/29 15:37:47 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	size_t	bytes;
	char	*buf;
	char	c;
	int		index;

	index = 0;
	if (fd == -1)
	{
		printf("Error al abrir el archivo.\n");
		return (NULL);
	}
	else
	{
		buf = (char *)malloc(10000000);
		if (!buf)
			return (NULL);
		bytes = read(fd, &c, 1); // each every one character from txt file
		while (bytes > 0)
		{
			buf[index] = c;
			index++;
			if (c == '\n' || c == EOF)
				break ;
			bytes = read(fd, &c, 1);
		}
		// Not getting more chars or errors
		if (index == 0 || bytes < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[index] = '\0';
		return (buf);
	}
}

int	main(void)
{
	int	fd;
	char *str;
	char *path;
	int	cont;

	path = "C:/Users/Rodrigo/OneDrive - brnomrs/Trabajos/CURSOS/gnlgithub/miFichero.txt";
	fd = open(path, O_RDONLY);
	cont = 0;
	while (cont < 6)
	{
		str = get_next_line(fd);
		printf("cont: %i\n", cont);
		printf("fd: %i, %s\n", fd, str);
		//printf("%s\n", get_next_line(fd));
		cont++;
	}
	return (0);
}
