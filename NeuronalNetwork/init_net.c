/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_net.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 01:26:23 by albaud            #+#    #+#             */
/*   Updated: 2023/02/14 15:08:17 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libia.h"
#include <stdio.h>

double	divs(double n)
{
	return (n / 2);
}

void	init_weights(t_net *net)
{
	int	i;

	net->bias = alo(net->info.hiden_layers + 1, sizeof(t_v));
	net->weights = alo(net->info.hiden_layers + 1, sizeof(t_mtx));
	net->weights[0] = m_rand(net->info.inputs,
			net->info.hiden_layers_size[0], -1, 1);
	i = 0;
	m_apply(&net->weights[i], divs);
	net->bias[0] = v_new(net->info.hiden_layers_size[0], 0);
	while (++i < net->info.hiden_layers)
	{
		net->weights[i] = m_rand(net->info.hiden_layers_size[i - 1],
				net->info.hiden_layers_size[i], -1, 1);
		net->bias[i] = v_new(net->info.hiden_layers_size[i], 0);
		m_apply(&net->weights[i], divs);
	}
	net->bias[i] = v_new(net->info.outputs, 0);
	net->weights[i] = m_rand(net->info.hiden_layers_size[i - 1],
			net->info.outputs, -1, 1);
	m_apply(&net->weights[i], divs);
}

double	r(double c)
{
	(void) c;
	return (rand_range(-1, 1) / 2);
}

void	net_clear(t_net *net)
{
	int	i;

	i = -1;
	while (++i)
	{
		m_apply(&net->weights[i], r);
		v_apply(&net->bias[i], r);
	}
}

t_net	*ia_init_net(t_net *res, char *name, t_info *info)
{
	int		i;

	res->info = *info;
	res->name = name;
	res->input = m_new(info->data_size, info->inputs, 0);
	res->hiden = alo(info->hiden_layers, sizeof(t_v));
	res->delta_hiden = alo(info->hiden_layers, sizeof(t_v));
	i = -1;
	while (++i < info->hiden_layers)
	{
		res->hiden[i] = v_new(info->hiden_layers_size[i], 0);
		res->delta_hiden[i] = v_new(info->hiden_layers_size[i], 0);
	}
	res->output = m_new(info->data_size, info->outputs, 0);
	res->predicted_output = v_new(info->outputs, 0);
	res->delta_output = v_new(info->outputs, 0);
	init_weights(res);
	mkdir(name, 0755);
	return (res);
}
