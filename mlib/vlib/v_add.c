/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_add.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:03:33 by albaud            #+#    #+#             */
/*   Updated: 2023/02/21 10:43:08 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vlib.h"

void	v_add(t_v *a, t_v *b, t_v *res)
{
	int		ite;

	ite = -1;
	while (++ite < a->size)
		res->arr[ite] = a->arr[ite] + b->arr[ite];
}

void	v_addn(t_v *a, double d)
{
	int		i;

	i = -1;
	while (++i < a->size)
	{
		a->arr[i] += d;
	}
}

void	v_add_a_x_b(t_v *a, double b, t_v *res)
{
	int		i;

	i = -1;
	while (++i < a->size)
		res->arr[i] += a->arr[i] * b;
}
