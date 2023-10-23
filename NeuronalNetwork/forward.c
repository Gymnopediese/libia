/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forward.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 02:07:21 by albaud            #+#    #+#             */
/*   Updated: 2023/10/23 18:22:40 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libia.h"


void	m_stuff(t_m *m, t_v *a, t_v *b, double learning)
{
	int	x;
	int	y;

	x = -1;
	while (++x < b->size)
	{
		y = -1;
		while (++y < a->size)
			m->arr[y].arr[x] += a->arr[y] * b->arr[x] * learning;
	}
}

void	v_addapply(t_v *a, t_v *b, double (*f)(double))
{
	int	i;

	i = -1;
	while (++i < a->size)
		a->arr[i] = f(a->arr[i] + b->arr[i]);
}

void	ia_forward(t_net *net, const t_v *input)
{
	int	i;

	m_hvdot(&net->weights[0], input, &net->hiden[0]);
	v_addapply(&net->hiden[0], &net->bias[0], net->function);
	i = 0;
	while (++i < net->info.hiden_layers)
	{
		m_hvdot(&net->weights[i], &net->hiden[i - 1], &net->hiden[i]);
		v_addapply(&net->hiden[i], &net->bias[i], net->function);
	}
	m_hvdot(&net->weights[i], &net->hiden[i - 1], &net->predicted_output);
	v_addapply(&net->predicted_output, &net->bias[i], net->function);
}

int	ia_predict(t_net *net, const t_v *input)
{
	ia_forward(net, input);
	return (v_maxi(&net->predicted_output));
}

void	ia_backward(t_net *net, t_v *input, t_v *output)
{
	int	i;

	v_subs(&net->predicted_output, output, &net->delta_output);
	i = net->info.hiden_layers - 1;
	m_stuff(&net->weights[i + 1], &net->hiden[i], &net->delta_output, net->info.learning);
	v_add_a_x_b(&net->delta_output, net->info.learning, &net->bias[i + 1]);
	v_apply(&net->hiden[i], net->function_prime);
	m_vvdot(&net->weights[i + 1], &net->delta_output, &net->delta_hiden[i]);
	v_mult(&net->hiden[i], &net->delta_hiden[i], &net->delta_hiden[i]);
	while (--i >= 0)
	{
		v_add_a_x_b(&net->delta_hiden[i + 1], net->info.learning, &net->bias[i + 1]);
		m_stuff(&net->weights[i + 1],
			&net->delta_hiden[i + 1], &net->delta_hiden[i], net->info.learning);
		v_apply(&net->hiden[i], net->function_prime);
		m_vvdot(&net->weights[i + 1],
			&net->delta_hiden[i + 1], &net->delta_hiden[i]);
		v_mult(&net->hiden[i], &net->delta_hiden[i], &net->delta_hiden[i]);
	}
	v_add_a_x_b(&net->delta_hiden[0], net->info.learning, &net->bias[0]);
	m_stuff(&net->weights[0], input, &net->delta_hiden[0], net->info.learning);
}
