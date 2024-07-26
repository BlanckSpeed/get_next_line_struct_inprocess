/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:40:23 by rodrigo           #+#    #+#             */
/*   Updated: 2024/07/26 13:56:23 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

void	gnl_bzero(void *s, size_t n)
{
	while (n--)
		((char *)s)[n] = 0;
}

void	*gnl_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(size * count);
	if (p == NULL)
		return (NULL);
	gnl_bzero(p, count * size);
	return (p);
}

char	*gnl_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

size_t	gnl_strlen(const char *s)
{
	const char	*cpy;

	cpy = s;
	while (*s)
		s++;
	return (s - cpy);
}

char	*gnl_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		++i;
	}
	if (i < n && src[i] == '\0')
	{
		while (dest[i] != '\0')
		{
			dest[i] = '\0';
			++i;
		}
	}
	return (dest);
}

char	*gnl_strdup(const char *s1)
{
	char	*dp;
	int	i;

	i = 0;
	dp = (char *)malloc(sizeof(char) * (gnl_strlen(s1) + 1));
	if (dp == NULL)
		return (0);
	while (s1[i])
	{
		dp[i] = s1[i];
		i++;
	}
	dp[i] = '\0';
	return (dp);
}


char	*gnl_strjoin(char const *s1, char const *s2)
{
	size_t	total_size;
	char	*join;
	int	i;

	i = 0;
	total_size = sizeof(char) * (gnl_strlen(s1) + gnl_strlen(s2) + 1);
	join = (char *)malloc(total_size);
	if (join == NULL)
		return (0);
	while (*s1)
		join[i++] = *s1++;
	while (*s2)
		join[i++] = *s2++;
	join[i] = '\0';
	return (join);
}

int	gnl_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

int	gnl_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t'
	|| c == '\v' || c == '\f' || c == '\r');
}
