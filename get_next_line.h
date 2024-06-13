/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 04:53:06 by marvin            #+#    #+#             */
/*   Updated: 2024/05/16 06:03:28 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h> // for printf and End Of File
#include <fcntl.h> // open file
#include <unistd.h>
#include <stdlib.h> // malloc
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd);
