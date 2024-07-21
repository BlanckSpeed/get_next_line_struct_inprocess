/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlendine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 22:25:01 by rlendine          #+#    #+#             */
/*   Updated: 2024/07/21 17:02:09 by rlendine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

char	*get_next_line(int fd)
{
	int		byte;
	int		index;
	char	buffer;
	char	*content;

	index = 0;
	content = (char *)malloc(10000);
	byte = read(fd, &buffer, 1);
	while (byte > 0)
	{
		content[index] = buffer;
		index++;
		if (buffer == '\n' || byte == 0)
			break ;
		byte = read(fd, &buffer, 1);
	}
	if (index == 0 || byte <= 0)
	{
		free(content);
		return (NULL);
	}
	content[index] = '\0';
	return (content);
}

int	main(void)
{
	int		fd;
	int		line_cont;
	char	*str;
	char	*path;

	line_cont = 0;
	path = "/home/rlendine/42/gnlRodrigo/miFichero";
	fd = open(path, O_RDONLY);
	while (line_cont++ < 10)
	{
		str = get_next_line(fd);
		printf("Linea: %i\n", line_cont);
		printf("fd: %i, contenido: %s\n", fd, str);
	}
	if (str != NULL)
		printf("%s\n", str);
	return (0);
}
