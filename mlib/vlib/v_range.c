/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_range.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:31:27 by albaud            #+#    #+#             */
/*   Updated: 2023/02/25 00:53:47 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vlib.h"

t_v	v_range(int min, int max)
{
	int	i;
	int	s;
	t_v	res;

	if (min > max)
		v_error("min bigger than max for range");
	res.arr = alo(max - min, sizeof(double));
	i = min;
	s = -1;
	res.size = max - min;
	while (i < max)
		res.arr[++s] = i++;
	return (res);
}
