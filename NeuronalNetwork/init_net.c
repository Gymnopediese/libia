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

void	print_net(t_net *net)
{
	printf("name: %s\n", net->info.name);
	printf("inputs: %d\n", net->info.inputs);
	printf("outputs: %d\n", net->info.outputs);
	printf("hiden_layers: %d\n", net->info.hiden_layers);
	printf("hiden_layers_size: ");
	for (int i = 0; i < net->info.hiden_layers; i++)
		printf("%d ", net->info.hiden_layers_size[i]);
	printf("\n");
	printf("learning: %f\n", net->info.learning);
}

void	init_weights(t_net *net)
{
	int	i;

	net->bias = new(net->info.hiden_layers + 1, sizeof(t_v));
	net->weights = new(net->info.hiden_layers + 1, sizeof(t_m));
	net->weights[0] = m_rand(net->info.inputs,
			net->info.hiden_layers_size[0], -MINMAXRAND, MINMAXRAND);
	i = 0;
	net->bias[0] = v_new(net->info.hiden_layers_size[0], 0);
	while (++i < net->info.hiden_layers)
	{
		net->weights[i] = m_rand(net->info.hiden_layers_size[i - 1],
				net->info.hiden_layers_size[i], -MINMAXRAND, MINMAXRAND);
		net->bias[i] = v_new(net->info.hiden_layers_size[i], 0);
	}
	net->weights[i] = m_rand(net->info.hiden_layers_size[i - 1],
			net->info.outputs, -MINMAXRAND, MINMAXRAND);
	net->bias[i] = v_new(net->info.outputs, 0);
}

void	set_function(t_net *res)
{

	if (res->info.function == FUNCTION_SIGMOID)
	{
		res->function = sigmoid;
		res->function_prime = sigmoid_prime;
	}
	else if (res->info.function == FUNCTION_RELU)
	{
		res->function = relu;
		res->function_prime = relu_prime;
	}
	else if (res->info.function == FUNCTION_TANH)
	{
		res->function = tanh;
		res->function_prime = tanh_prime;
	}
	else if (res->info.function == FUNCTION_SOFTMAX)
	{
		res->function = softmax;
		res->function_prime = softmax_prime;
	}
}

void	init_neuronal_network(t_net *res, t_info infos)
{
	int		i;

	res->info = infos;
	set_function(res);
	res->hiden = new(res->info.hiden_layers, sizeof(t_v));
	res->delta_hiden = new(res->info.hiden_layers, sizeof(t_v));
	i = -1;
	while (++i < res->info.hiden_layers)
	{
		res->hiden[i] = v_new(res->info.hiden_layers_size[i], 0);
		res->delta_hiden[i] = v_new(res->info.hiden_layers_size[i], 0);
	}
	res->predicted_output = v_new(res->info.outputs, 0);
	res->delta_output = v_new(res->info.outputs, 0);
	init_weights(res);
}
