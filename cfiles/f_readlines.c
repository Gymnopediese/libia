/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_readlines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 00:44:51 by albaud            #+#    #+#             */
/*   Updated: 2023/02/14 00:50:37 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cfiles.h"

char	*f_strcpy_to(char **src, char target)
{
	int		size;
	char	*res;

	size = ft_strlen_to(*src, target);
	res = calloc(size + 1, 1);
	if (res == 0)
		return (0);
	ft_strncpy(res, *src, size);
	*src = &(*src)[size + 1];
	return (res);
}

char	**f_readlines(char *file_name)
{
	char	*buffer;
	char	*to_free;
	char	**res;
	int		size;
	int		i;

	buffer = f_read(file_name);
	to_free = buffer;
	if (buffer == 0)
		return (0);
	size = ft_count(buffer, '\n');
	res = calloc(size, sizeof(char *) + 1);
	if (res == 0)
		return (0);
	i = -1;
	while (++i < size)
		res[i] = f_strcpy_to(&buffer, '\n');
	res[i] = 0;
	free(to_free);
	return (res);
}
