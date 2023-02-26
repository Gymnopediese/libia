/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_new.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:28:46 by albaud            #+#    #+#             */
/*   Updated: 2023/02/23 15:17:22 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vlib.h"

void	v_copy(t_v *dest, t_v *src)
{
	int	ite;

	ite = -1;
	while (++ite < dest->size)
		dest->arr[ite] = src->arr[ite];
}

t_v	v_new(int size, double init)
{
	t_v	res;
	int	ite;

	ite = -1;
	res.arr = calloc(size, sizeof(double));
	if (res.arr == 0)
		v_error("null pointer returned by malloc");
	res.size = size;
	while (++ite < size)
		res.arr[ite] = init;
	return (res);
}
