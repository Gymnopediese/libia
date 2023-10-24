/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vmfunctions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:34:20 by albaud            #+#    #+#             */
/*   Updated: 2023/10/24 11:34:55 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libia.h"

void	m_stuff(t_m *m, const t_v *a, const t_v *b, const double learning)
{
	register int	x;
	register int	y;

	x = -1;
	while (++x < b->size)
	{
		y = -1;
		while (++y < a->size)
			m->arr[y].arr[x] += a->arr[y] * b->arr[x] * learning;
	}
}

void	propagation(t_m *weights, t_v *hiden, t_v *right, t_v *left, t_net *net)
{
	register int	x;

	x = -1;
	while (++x < hiden->size)
	{
		hiden->arr[x] = net->function_prime(hiden->arr[x]);
		left->arr[x] = v_dot(&weights->arr[x], right) * hiden->arr[x];
	}
}

void	v_addapply(t_v *a, const t_v *b, double (*f)(double))
{
	int	i;

	i = -1;
	while (++i < a->size)
		a->arr[i] = f(a->arr[i] + b->arr[i]);
}
