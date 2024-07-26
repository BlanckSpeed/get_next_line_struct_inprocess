/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlendine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 22:25:01 by rlendine          #+#    #+#             */
/*   Updated: 2024/07/26 14:25:26 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*find_line(char **final_buffer)
{
	char	*line;
	char	*newline_position;
	char	*temp;

	newline_position = gnl_strchr(*final_buffer, '\n');
	if (newline_position)
	{
		newline_position++;
		line = gnl_calloc(gnl_strlen(*final_buffer) + 1, sizeof(char));
		gnl_strncpy(line, *final_buffer, newline_position - *final_buffer);
		temp = gnl_strdup(newline_position + 1);
		free(*final_buffer);
		*final_buffer = temp;
		if ((*final_buffer)[0] == '\0')
		{
			free(*final_buffer);
			*final_buffer = nil;
		}
	}
	else
	{
		line = gnl_strdup(*final_buffer);
		free(*final_buffer);
		*final_buffer = nil;
	}
	return (line);
}

static char	*read_file(int fd)
{
	int	bytes;
	char	*content;
	char	temp[2];

	content = gnl_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (content == nil)
		return (nil);
	bytes = 0;
	while (bytes < BUFFER_SIZE)
	{
		if (read(fd, temp, 1) <= 0)
		{
			if (bytes == 0)
			{
				free(content);
				return (nil);
			}
			break;
		}
		temp[1] = '\0';
		content = gnl_strjoin(content, temp);
		bytes++;
		if (temp[0] == '\n')
			break;
	}
	return (content);
}

char	*get_next_line(int fd)
{
	static char	*final_buffer;
	char	*line;
	char	*temp_buffer;
	int	i;

	i = 0;
	if (fd < 0 || read(fd, nil, 0) < 0 || BUFFER_SIZE <= 0)
		return (nil);
	if (!final_buffer)
		final_buffer = gnl_calloc(1, sizeof(char));
	while (!gnl_strchr(final_buffer, '\n'))
	{
		temp_buffer = read_file(fd);
		if (!temp_buffer)
		{
			free (final_buffer);
			return (nil);
		}
		while (temp_buffer[i])
		{
			if (!gnl_isprint(temp_buffer[i]) && !gnl_isspace(temp_buffer[i]))
			{
				free(temp_buffer);
				free(final_buffer);
				return (nil);
			}
			i++;
		}
		final_buffer = gnl_strjoin(final_buffer, temp_buffer);
		free(temp_buffer);
	}
	line = find_line(&final_buffer);
	return (line);
}

int	main(void)
{
	int		fd;
	int		cont;
	char	*str;
	char	*path;

	cont = 0;
	path = "/home/rodrigo/Proyectos42/gnlgithub/miFichero";
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file");
		return (1);
	}

	while(1)
	{
		str = get_next_line(fd);
		if(str == nil)
			break ;
		cont++;
		printf("[%d]:%s\n", cont, str);
		free(str);
		str = nil;
	}
	close(fd);
	return (0);
}
