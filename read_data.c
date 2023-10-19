/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 00:47:33 by albaud            #+#    #+#             */
/*   Updated: 2023/10/04 12:55:25 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libia.h"
#include <stdlib.h>

t_data	read_csv_file(char *path, int inp_size, int out_size, int start, int length)
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
		res.output.arr[i - start].arr[atoi(temp.arrays[i].chars)] = 1;
		atoia(res.input.arr[i - start].arr, &temp.arrays[i].chars[2], ",");
	}
	delete_scope(0);
	return (res);
}
