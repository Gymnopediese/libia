/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_vdot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:05:10 by albaud            #+#    #+#             */
/*   Updated: 2023/02/18 10:13:28 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "mlib.h"

void	m_vvdot(t_mtx *a, t_v *b, t_v *res)
{
	int		x;

	x = -1;
	while (++x < a->size)
		res->arr[x] = v_dot(&a->arr[x], b);
}

void	m_hvdot(t_mtx *a, t_v *b, t_v *res)
{
	int		x;
	int		y;

	x = -1;
	while (++x < a->arr->size)
	{
		y = -1;
		res->arr[x] = 0;
		while (++y < a->size)
			res->arr[x] += a->arr[y].arr[x] * b->arr[y];
	}
}
