/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gan.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 00:31:40 by albaud            #+#    #+#             */
/*   Updated: 2023/03/13 23:54:30 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libia.h"

void	clone(t_gan *gan)
{
	int		x;
	int		y;

	x = -1;
	while (++x < gan->inspector.weights[0].size)
	{
		y = -1;
		while (++y < gan->inspector.weights[0].arr->size)
		{
			gan->generator.weights[1].arr[y].arr[x]
				= gan->inspector.weights[0].arr[x].arr[y];
		}
	}
	while (++x < gan->inspector.weights[1].size)
	{
		y = -1;
		while (++y < gan->generator.weights[0].size)
		{
			gan->generator.weights[0].arr[y].arr[x]
				= gan->inspector.weights[1].arr[x].arr[0];
		}
	}

}

double	ran(double n)
{
	(void)n;
	return (rand_range(0, 1));
}

void	fake(t_gan *gan, t_v *inp, t_v *out)
{
	v_apply(inp, ran);
	ia_forward(&gan->generator, inp);
	ia_forward(&gan->inspector, &gan->generator.predicted_output);
	//out->arr[0] = -log(1 - gan->inspector.predicted_output.arr[0]);
	out->arr[0] = 0;
	ia_backward(&gan->inspector, &gan->generator.predicted_output, out);
	clone(gan);
}

void	reel(t_gan *gan, t_v *inp, t_v *out)
{
	ia_forward(&gan->inspector, inp);
	//out->arr[0] = -log(gan->inspector.predicted_output.arr[0]);
	out->arr[0] = 1;
	ia_backward(&gan->inspector, inp, out);
}

void	train_gan(t_gan *gan, int iter)
{
	int	i;
	int	k;
	t_v	inp;
	t_v	out;
	int	max;

	max = 60000 * 2;
	inp = v_new(10, 0);
	out = v_new(1, 0);
	i = -1;
	while (++i < iter)
	{
		progressbar("they are fighting", i, iter);
		k = -1;
		while (++k < max)
		{
			progressbar("one lol", k, max);
			if (k % 2)
				fake(gan, &inp, &out);
			else
				reel(gan, &gan->data.input.arr[k / 2], &out);
		}
	}
	progressbar("they are fighting", i, iter);
	free(inp.arr);
}

t_gan	init_gan(void)
{
	t_gan	gan;

	init_net(&gan.inspector,
		"inspector", 784, 1, (int []){50}, 1, sigmoid, sigmoid_prime);
	init_net(&gan.generator,
		"generator", 784, 1, (int []){50}, 784, sigmoid, sigmoid_prime);
	gan.generator.bias = gan.inspector.bias;
	printf("%i %i\n", gan.generator.bias->size, gan.inspector.bias->size);
	printf("%i %i\n", gan.generator.weights[0].size, gan.inspector.weights[1].arr->size);
	printf("%i %i\n", gan.generator.weights[0].arr->size, gan.inspector.weights[1].size);
	printf("%i %i\n", gan.generator.weights[1].size, gan.inspector.weights[0].arr->size);
	printf("%i %i\n", gan.generator.weights[1].arr->size, gan.inspector.weights[0].size);
	return (gan);
}
