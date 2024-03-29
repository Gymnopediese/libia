/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_voisin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:03:17 by albaud            #+#    #+#             */
/*   Updated: 2023/10/25 11:35:22 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libia.h"

double	ann_k_voisins_om(t_m *input, t_m *output, t_v *guess, int v)
{
	t_v		min;
	t_v		val;
	int		i;
	int		j;
	double	d;

	min = v_new(v, 99999999);
	val = v_new(v, 0);
	i = -1;
	while (++i < input->size)
	{
		d = v_dist(&input->arr[i], guess);
		j = -1;
		while (++j < v)
		{
			if (min.arr[j] > d)
			{
				min.arr[j] = d;
				val.arr[j] = v_maxi(&output->arr[i]);
				break ;
			}
		}
	}
	return (v_omax(&val));
}

double	ann_k_voisins(t_m *input, t_v *output, t_v *guess, int v)
{
	t_v		min;
	t_v		val;
	int		i;
	int		j;
	double	d;

	min = v_new(v, 99999999);
	val = v_new(v, 0);
	i = -1;
	while (++i < input->size)
	{
		d = v_dist(&input->arr[i], guess);
		j = -1;
		while (++j < v)
		{
			if (min.arr[j] > d)
			{
				min.arr[j] = d;
				val.arr[j] = output->arr[i];
				break ;
			}
		}
	}
	return (v_omax(&val));
}
