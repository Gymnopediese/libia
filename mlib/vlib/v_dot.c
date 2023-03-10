/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_dot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:01:16 by albaud            #+#    #+#             */
/*   Updated: 2023/02/17 12:01:47 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vlib.h"

double	v_dot(t_v *a, t_v *b)
{
	double	sum;
	int		ite;

	sum = 0;
	ite = -1;
	while (++ite < a->size)
		sum += a->arr[ite] * b->arr[ite];
	return (sum);
}
