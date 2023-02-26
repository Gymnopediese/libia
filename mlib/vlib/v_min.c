/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_min.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:37:35 by albaud            #+#    #+#             */
/*   Updated: 2023/02/24 10:43:53 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vlib.h"

int	v_mini(t_v *a)
{
	int		i;
	double	min;
	double	ind;

	i = -1;
	min = 999999999;
	ind = 0;
	while (++i < a->size)
	{
		if (a->arr[i] < min)
		{
			min = a->arr[i];
			ind = i;
		}
	}
	return (ind);
}

double	v_min(t_v *a)
{
	double	min;
	int		i;

	min = 99999999;
	i = -1;
	while (++i < a->size)
	{
		if (a->arr[i] < min)
			min = a->arr[i];
	}
	return (min);
}
