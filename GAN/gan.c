/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gan.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 00:31:40 by albaud            #+#    #+#             */
/*   Updated: 2023/03/17 19:57:41 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libia.h"

// void	clone(t_gan *gan)
// {
// 	int		x;
// 	int		y;

// 	x = -1;
// 	while (++x < gan->inspector.weights[0].size)
// 	{
// 		y = -1;
// 		while (++y < gan->inspector.weights[0].arr->size)
// 		{
// 			gan->generator.weights[1].arr[y].arr[x]
// 				= gan->inspector.weights[0].arr[x].arr[y];
// 		}
// 	}
// 	while (++x < gan->inspector.weights[1].size)
// 	{
// 		y = -1;
// 		while (++y < gan->generator.weights[0].size)
// 		{
// 			gan->generator.weights[0].arr[y].arr[x]
// 				= gan->inspector.weights[1].arr[x].arr[0];
// 		}
// 	}
// }

// void	fake(t_gan *gan, t_v *inp, t_v *out)
// {
// 	v_apply(inp, ran);
// 	ia_forward(&gan->generator, inp);
// 	ia_forward(&gan->inspector, &gan->generator.predicted_output);
// 	//out->arr[0] = -log(1 - gan->inspector.predicted_output.arr[0]);
// 	out->arr[0] = 0;
// 	ia_backward(&gan->inspector, &gan->generator.predicted_output, out);
// 	clone(gan);
// }

// void	reel(t_gan *gan, t_v *inp, t_v *out)
// {
// 	ia_forward(&gan->inspector, inp);
// 	//out->arr[0] = -log(gan->inspector.predicted_output.arr[0]);
// 	out->arr[0] = 1;
// 	ia_backward(&gan->inspector, inp, out);
// }

double	ran(double n)
{
	(void)n;
	return (rand_range(0, 1));
}

void	ia_backward_inp(t_net *net, t_v *input, t_v *output)
{
	int			i;
	static t_v	delta_input = (t_v){0, 0};

	if (delta_input.arr == 0)
		delta_input = v_new(net->info.inputs, 0);
	v_subs(&net->predicted_output, output, &net->delta_output);
	i = net->info.hiden_layers - 1;
	v_apply(&net->hiden[i], net->function);
	m_vvdot(&net->weights[i + 1], &net->delta_output, &net->delta_hiden[i]);
	v_mult(&net->hiden[i], &net->delta_hiden[i], &net->delta_hiden[i]);
	while (--i >= 0)
	{
		v_apply(&net->hiden[i], net->function_prime);
		m_vvdot(&net->weights[i + 1],
			&net->delta_hiden[i + 1], &net->delta_hiden[i]);
		v_mult(&net->hiden[i], &net->delta_hiden[i], &net->delta_hiden[i]);
	}
	// printf("\n");
	// v_xprint(input, 10);
	v_apply(input, net->function_prime);
	// v_xprint(input, 10);
	m_vvdot(&net->weights[0], &net->delta_hiden[0], input);
	// v_xprint(&delta_input, 10);
	// v_mult(input, &delta_input, input);
	// v_xprint(input, 10);
	// exit(0);
}

void	train_inspector(t_gan *gan, t_v *t_inp, t_v *f_inp, t_v *out)
{
	ia_forward(&gan->inspector, t_inp);
	out->arr[0] = 1;
	ia_backward(&gan->inspector, t_inp, out);
	v_apply(f_inp, ran);
	ia_forward(&gan->generator, f_inp);
	ia_forward(&gan->inspector, &gan->generator.predicted_output);
	out->arr[0] = 0;
	ia_backward(&gan->inspector, &gan->generator.predicted_output, out);
}

void	train_generator(t_gan *gan, t_v *g_inp, t_v *inp, t_v *out)
{
	v_apply(g_inp, ran);
	ia_forward(&gan->generator, g_inp);
	v_copy(inp, &gan->generator.predicted_output);
	ia_forward(&gan->inspector, inp);
	out->arr[0] = 1;
	ia_backward_inp(&gan->inspector, inp, out);
	ia_backward(&gan->generator, g_inp, inp);
}

void	train_gan(t_gan *gan, int iter)
{
	int	i;
	int	k;
	t_v	g_inp;
	t_v	out;
	t_v	inp;
	int	max;

	max = 3000;
	g_inp = v_new(784, 0);
	out = v_new(1, 0);
	inp = v_new(784, 0);
	i = -1;
	while (++i < iter)
	{
		progressbar("they are fighting", i, iter);
		k = -1;
		while (++k < max)
		{
			progressbar("sbufight", k, max);
			train_inspector(gan, &gan->data.input.arr[(int)rand_range(0, 60000)], &g_inp, &out);
			train_generator(gan, &g_inp, &inp, &out);
		}
	}
	progressbar("they are fighting", i, iter);
	free(inp.arr);
}

t_gan	init_gan(void)
{
	t_gan	gan;

	init_net(&gan.inspector,
		"inspector", 784, 1, (int []){77}, 1, sigmoid, sigmoid_prime);
	init_net(&gan.generator,
		"generator", 784, 1, (int []){77}, 784, sigmoid, sigmoid_prime);
	printf("%i %i\n", gan.generator.bias->size, gan.inspector.bias->size);
	printf("%i %i\n", gan.generator.weights[0].size, gan.inspector.weights[1].arr->size);
	printf("%i %i\n", gan.generator.weights[0].arr->size, gan.inspector.weights[1].size);
	printf("%i %i\n", gan.generator.weights[1].size, gan.inspector.weights[0].arr->size);
	printf("%i %i\n", gan.generator.weights[1].arr->size, gan.inspector.weights[0].size);
	return (gan);
}
