/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 00:41:05 by albaud            #+#    #+#             */
/*   Updated: 2023/02/14 00:43:32 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cfiles.h"

int	f_file_size(char *file_name)
{
	int		res;
	int		size;
	int		fd;
	char	tuffer[1000000];

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (-1);
	size = read(fd, tuffer, 999999);
	res = 0;
	while (size > 0)
	{
		res += size;
		size = read(fd, tuffer, 999999);
		if (size == -1)
			return (size);
	}
	close(fd);
	return (res);
}