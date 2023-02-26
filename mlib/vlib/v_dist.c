/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_dist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:30:17 by albaud            #+#    #+#             */
/*   Updated: 2023/02/15 21:31:45 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vlib.h"

double	v_dist(t_v *a, t_v *b)
{
	double	sum;
	int		ite;

	sum = 0;
	ite = -1;
	while (++ite < a->size)
		sum += pow(a->arr[ite] - b->arr[ite], 2);
	return (sqrt(sum));
}
