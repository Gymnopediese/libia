/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   train.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:46:02 by albaud            #+#    #+#             */
/*   Updated: 2023/03/07 23:26:32 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libia.h"

void	ia_ntrain(t_net *net, int n)
{
	int	i;
	int	j;

	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < net->info.data_size)
		{
			ia_forward(net, &net->input.arr[j]);
			ia_backward(net, &net->input.arr[j], &net->output.arr[j]);
		}
	}
	ia_save(net, net->name);
}

void	ia_random_train(t_net *net, int n)
{
	int		i;
	int		j;
	t_v		v;

	i = -1;
	v = v_range(0, net->info.data_size);
	while (++i < n)
	{
		j = -1;
		v_shuffle(&v);
		while (++j < net->info.data_size)
		{
			progressbar("step", j, net->info.data_size);
			ia_forward(net, &net->input.arr[(int)v.arr[j]]);
			ia_backward(net, &net->input.arr[(int)v.arr[j]],
				&net->output.arr[(int)v.arr[j]]);
		}
		ia_save(net, ft_itoa(rand_range(1000000, 9999999)));
	}
}

void	ia_train_test(t_net *net, int n, double (*test)(t_net *))
{
	int		i;
	int		j;
	double	s;

	i = -1;
	s = 0;
	if (test)
		s = test(net);
	printf("%f %i \n", s, i + 1);
	while (++i < n)
	{
		j = -1;
		while (++j < net->info.data_size)
		{
			ia_forward(net, &net->input.arr[j]);
			ia_backward(net, &net->input.arr[j], &net->output.arr[j]);
		}
		if (test)
			s = test(net);
		printf("%f %i \n", s, i + 1);
		ia_save(net, ft_itoa(s * 1000));
	}
}
