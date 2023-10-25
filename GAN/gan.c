/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gan.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 00:31:40 by albaud            #+#    #+#             */
/*   Updated: 2023/10/25 11:35:25 by albaud           ###   ########.fr       */
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
// 	ann_forward(&gan->generator, inp);
// 	ann_forward(&gan->inspector, &gan->generator.predicted_output);
// 	//out->arr[0] = -log(1 - gan->inspector.predicted_output.arr[0]);
// 	out->arr[0] = 0;
// 	ann_backward(&gan->inspector, &gan->generator.predicted_output, out);
// 	clone(gan);
// }

// void	reel(t_gan *gan, t_v *inp, t_v *out)
// {
// 	ann_forward(&gan->inspector, inp);
// 	//out->arr[0] = -log(gan->inspector.predicted_output.arr[0]);
// 	out->arr[0] = 1;
// 	ann_backward(&gan->inspector, inp, out);
// }

double	ran(double n)
{
	(void)n;
	return (randdouble(0, 1));
}

void	ann_backward_inp(t_ann *ann, t_v *input, t_v *output)
{
	int			i;
	static t_v	delta_input = (t_v){0, 0};

	if (delta_input.arr == 0)
		delta_input = v_new(ann->info.inputs, 0);
	v_subs(&ann->predicted_output, output, &ann->delta_output);
	i = ann->info.hiden_layers - 1;
	v_apply(&ann->hiden[i], ann->function);
	m_vvdot(&ann->weights[i + 1], &ann->delta_output, &ann->delta_hiden[i]);
	v_mult(&ann->hiden[i], &ann->delta_hiden[i], &ann->delta_hiden[i]);
	while (--i >= 0)
	{
		v_apply(&ann->hiden[i], ann->function_prime);
		m_vvdot(&ann->weights[i + 1],
			&ann->delta_hiden[i + 1], &ann->delta_hiden[i]);
		v_mult(&ann->hiden[i], &ann->delta_hiden[i], &ann->delta_hiden[i]);
	}
	// printf("\n");
	// v_xprint(input, 10);
	v_apply(input, ann->function_prime);
	// v_xprint(input, 10);
	m_vvdot(&ann->weights[0], &ann->delta_hiden[0], input);
	// v_xprint(&delta_input, 10);
	// v_mult(input, &delta_input, input);
	// v_xprint(input, 10);
	// exit(0);
}

void	train_inspector(t_gan *gan, t_v *t_inp, t_v *f_inp, t_v *out)
{
	ann_forward(&gan->inspector, t_inp);
	out->arr[0] = 1;
	ann_backward(&gan->inspector, t_inp, out);
	v_apply(f_inp, ran);
	ann_forward(&gan->generator, f_inp);
	ann_forward(&gan->inspector, &gan->generator.predicted_output);
	out->arr[0] = 0;
	ann_backward(&gan->inspector, &gan->generator.predicted_output, out);
}

void	train_generator(t_gan *gan, t_v *g_inp, t_v *inp, t_v *out)
{
	v_apply(g_inp, ran);
	ann_forward(&gan->generator, g_inp);
	v_copy(inp, &gan->generator.predicted_output);
	ann_forward(&gan->inspector, inp);
	out->arr[0] = 1;
	ann_backward_inp(&gan->inspector, inp, out);
	ann_backward(&gan->generator, g_inp, inp);
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
		// progressbar("they are fighting", i, iter);
		k = -1;
		while (++k < max)
		{
			// progressbar("sbufight", k, max);
			train_inspector(gan, &gan->data.input.arr[(int)randint(0, 60000)], &g_inp, &out);
			train_generator(gan, &g_inp, &inp, &out);
		}
	}
	// progressbar("they are fighting", i, iter);
	free(inp.arr);
}

// t_gan	init_gan(void)
// {
// 	t_gan	gan;

// 	init_neuronal_network(&gan.inspector,
// 		"inspector", 784, 1, (int []){77}, 1, sigmoid, sigmoid_prime);
// 	init_neuronal_network(&gan.generator,
// 		"generator", 784, 1, (int []){77}, 784, sigmoid, sigmoid_prime);
// 	printf("%i %i\n", gan.generator.bias->size, gan.inspector.bias->size);
// 	printf("%i %i\n", gan.generator.weights[0].size, gan.inspector.weights[1].arr->size);
// 	printf("%i %i\n", gan.generator.weights[0].arr->size, gan.inspector.weights[1].size);
// 	printf("%i %i\n", gan.generator.weights[1].size, gan.inspector.weights[0].arr->size);
// 	printf("%i %i\n", gan.generator.weights[1].arr->size, gan.inspector.weights[0].size);
// 	return (gan);
// }
