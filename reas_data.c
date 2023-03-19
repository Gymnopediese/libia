/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reas_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 00:47:33 by albaud            #+#    #+#             */
/*   Updated: 2023/03/20 00:47:47 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libia.h"

t_data	read_data(char *path, int inp_size, int out_size, int start)
{
	char	**temp;
	int		i;
	t_data	res;

	temp = f_readlines(path);
	i = start - 1;
	res.input = m_new(60000, inp_size, 0);
	res.output = m_new(60000, out_size, 0);
	res.size = 60000;
	while (temp[++i])
	{
		ft_atoia_fast(&temp[i][2], ',', res.input.arr[i - 1].arr, 255);
		if (ft_atoi(temp[i]) < out_size)
			res.output.arr[i - 1].arr[ft_atoi(temp[i])] = 1;
	}
	ft_free_pp((void **)temp);
	return (res);
}
