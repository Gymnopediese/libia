/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 00:47:33 by albaud            #+#    #+#             */
/*   Updated: 2023/09/27 09:28:04 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libia.h"
#include <stdlib.h>
void	ft_atoia_fast(char *str, char split, double *buffer, int div)
{
	int		i;
	int		k;

	i = -1;
	k = -1;
	while (str[++k])
	{
		buffer[++i] = atof(&str[k]) / div;
		while (str[++k] && str[k] != split)
			;
	}
}


t_data	read_csv_file(char *path, int inp_size, int out_size, int start, int length, double div)
{
	t_arr	temp;
	size_t	i;
	t_data	res;

	i = start - 1;
	res.input = m_new(length, inp_size, 0);
	res.output = m_new(length, out_size, 0);
	new_scope();
	temp = readlines(path);
	res.size = length;
	while (++i < temp.size)
	{
		ft_atoia_fast(&temp.arrays[i].chars[2], ',', res.input.arr[i - 1].arr, div);
	// 	if (atof(temp.arrays[i].chars) < out_size)
	// 		res.output.arr[i - 1].arr[atof(temp.arrays[i].chars)] = 1;
	}
	delete_scope(0);
	return (res);
}
