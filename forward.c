/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forward.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 02:07:21 by albaud            #+#    #+#             */
/*   Updated: 2023/02/25 02:02:00 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libia.h"
#include "../header.h"

#define FUNC sigmoid
#define FUNCP sigmoid_prime
#define LEARNING -0.01

void	m_stuff(t_mtx *m, t_v *a, t_v *b)
{
	int	x;
	int	y;

	x = -1;
	while (++x < b->size)
	{
		y = -1;
		while (++y < a->size)
		{
			m->arr[y].arr[x] += a->arr[y] * b->arr[x] * LEARNING;
		}
	}
}

void	ia_forward(t_net *net, t_v *input)
{
	int	i;

	m_hvdot(&net->weights[0], input, &net->hiden[0]);
	v_add(&net->hiden[0], &net->bias[0], &net->hiden[0]);
	v_apply(&net->hiden[0], FUNC);
	i = 0;
	while (++i < net->info.hiden_layers)
	{
		m_hvdot(&net->weights[i], &net->hiden[i - 1], &net->hiden[i]);
		v_add(&net->hiden[i], &net->bias[i], &net->hiden[i]);
		v_apply(&net->hiden[i], FUNC);
	}
	m_hvdot(&net->weights[i], &net->hiden[i - 1], &net->predicted_output);
	v_add(&net->predicted_output, &net->bias[i], &net->predicted_output);
	v_apply(&net->predicted_output, FUNC);
}

void	ia_backward(t_net *net, t_v *input, t_v *output)
{
	int	i;

	v_subs(&net->predicted_output, output, &net->delta_output);
	i = net->info.hiden_layers - 1;
	m_stuff(&net->weights[i + 1], &net->hiden[i], &net->delta_output);
	v_add_a_x_b(&net->delta_output, LEARNING, &net->bias[i + 1]);

	v_apply(&net->hiden[i], FUNCP);
	m_vvdot(&net->weights[i + 1], &net->delta_output, &net->delta_hiden[i]);
	v_mult(&net->hiden[i], &net->delta_hiden[i], &net->delta_hiden[i]);
	while (--i >= 0)
	{
		v_add_a_x_b(&net->delta_hiden[i + 1], LEARNING, &net->bias[i + 1]);
		m_stuff(&net->weights[i + 1],
			&net->delta_hiden[i + 1], &net->delta_hiden[i]);
		v_apply(&net->hiden[i], FUNCP);
		m_vvdot(&net->weights[i + 1],
			&net->delta_hiden[i + 1], &net->delta_hiden[i]);
		v_mult(&net->hiden[i], &net->delta_hiden[i], &net->delta_hiden[i]);
	}
	v_add_a_x_b(&net->delta_hiden[0], LEARNING, &net->bias[0]);
	m_stuff(&net->weights[0], input, &net->delta_hiden[0]);
}

int	stp(double a)
{
	return (a < -1 || a > 1);
}
