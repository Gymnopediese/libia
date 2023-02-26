/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_average.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:43:38 by albaud            #+#    #+#             */
/*   Updated: 2023/02/21 11:14:54 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vlib.h"

void	v_raverage(t_v *a)
{
	double	min;
	int		i;

	min = v_min(a);
	if (min < 0)
		v_addn(a, -min);
	min = v_sum(a);
	if (min == 0)
		return ;
	i = -1;
	while (++i < a->size)
		a->arr[i] /= min;
}
