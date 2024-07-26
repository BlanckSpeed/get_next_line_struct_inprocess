/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlendine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:28:21 by rlendine          #+#    #+#             */
/*   Updated: 2024/07/26 14:30:03 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif

# define nil NULL
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*line_read;
	struct s_list	*next_line;
}	t_list;

char	*get_next_line(int fd);
void	*gnl_calloc(size_t count, size_t size);
char	*gnl_strchr(const char *s, int c);
char	*gnl_strncpy(char *dest, char *src, unsigned int n);
char	*gnl_strdup(const char *s1);
char	*gnl_strjoin(char const *s1, char const *s2);
size_t	gnl_strlen(const char *s);
void	gnl_bzero(void *s, size_t n);
int	gnl_isprint(int c);
int	gnl_isspace(char c);
#endif
