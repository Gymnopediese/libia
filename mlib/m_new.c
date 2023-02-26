/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_new.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:26:05 by albaud            #+#    #+#             */
/*   Updated: 2023/02/15 21:46:20 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlib.h"

t_mtx	m_new(int x, int y, int init)
{
	t_mtx	res;

	res.size = x;
	res.arr = calloc(x, sizeof(t_v));
	if (res.arr == 0)
		return (res);
	while (--x >= 0)
		res.arr[x] = v_new(y, init);
	return (res);
}
