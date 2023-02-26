/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_omax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:30:26 by albaud            #+#    #+#             */
/*   Updated: 2023/02/21 11:53:17 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vlib.h"

double	v_max(t_v *a)
{
	int		i;
	double	max;

	i = -1;
	max = -999999999;
	while (++i < a->size)
	{
		if (a->arr[i] > max)
		{
			max = a->arr[i];
		}
	}
	return (max);
}

int	v_maxi(t_v *a)
{
	int		i;
	double	max;
	double	ind;

	i = -1;
	max = -999999999;
	ind = 0;
	while (++i < a->size)
	{
		if (a->arr[i] > max)
		{
			max = a->arr[i];
			ind = i;
		}
	}
	return (ind);
}

double	v_omax(t_v *a)
{
	int		i;
	int		j;
	int		max;
	double	val;
	double	t;

	i = -1;
	max = -999999;
	val = 0;
	while (++i < a->size - 1)
	{
		j = i + 1;
		t = 1;
		while (++j < a->size)
		{
			if (a->arr[j] == a->arr[i])
				t++;
		}
		if (t > max)
		{
			max = t;
			val = a->arr[i];
		}
	}
	return (val);
}
