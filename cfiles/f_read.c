/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_read.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 00:43:05 by albaud            #+#    #+#             */
/*   Updated: 2023/02/14 00:49:56 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cfiles.h"

char	*f_read(char *file_name)
{
	int		size;
	char	*buffer;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (0);
	size = f_file_size(file_name);
	buffer = malloc(size + 1);
	if (buffer == 0)
		return (0);
	if (read(fd, buffer, size) == -1)
		return (0);
	buffer[size] = 0;
	close(fd);
	return (buffer);
}
