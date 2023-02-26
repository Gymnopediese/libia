/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_rand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 22:20:59 by albaud            #+#    #+#             */
/*   Updated: 2023/02/15 22:21:43 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vlib.h"

t_v	v_rand(int size, int min, int max)
{
	t_v	res;
	int	ite;

	ite = -1;
	res.arr = calloc(size, sizeof(double));
	if (res.arr == 0)
		v_error("null pointer returned by malloc");
	res.size = size;
	while (++ite < size)
		res.arr[ite] = rand_range(min, max);
	return (res);
}
