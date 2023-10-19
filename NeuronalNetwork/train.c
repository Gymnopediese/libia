/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   train.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:46:02 by albaud            #+#    #+#             */
/*   Updated: 2023/10/18 09:49:37 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libia.h"

// void	ia_ntrain(t_net *net, int n)
// {
// 	int	i;
// 	int	j;

// 	i = -1;
// 	while (++i < n)
// 	{
// 		j = -1;
// 		while (++j < net->info.data_size)
// 		{
// 			ia_forward(net, &net->input.arr[j]);
// 			ia_backward(net, &net->input.arr[j], &net->output.arr[j]);
// 		}
// 	}
// 	ia_save(net, net->name);
// }

// void	ia_random_train(t_net *net, int n)
// {
// 	int		i;
// 	int		j;
// 	t_v		v;

// 	i = -1;
// 	v = v_range(0, net->info.data_size);
// 	while (++i < n)
// 	{
// 		j = -1;
// 		v_shuffle(&v);
// 		while (++j < net->info.data_size)
// 		{
// 			progressbar("step", j, net->info.data_size);
// 			ia_forward(net, &net->input.arr[(int)v.arr[j]]);
// 			ia_backward(net, &net->input.arr[(int)v.arr[j]],
// 				&net->output.arr[(int)v.arr[j]]);
// 		}
// 		ia_save(net, ft_itoa(rand_range(1000000, 9999999)));
// 	}
// }

// void	ia_train_test(t_net *net, int n, double (*test)(t_net *))
// {
// 	int		i;
// 	int		j;
// 	double	s;

// 	i = -1;
// 	s = 0;
// 	if (test)
// 		s = test(net);
// 	printf("%f %i \n", s, i + 1);
// 	while (++i < n)
// 	{
// 		j = -1;
// 		while (++j < net->info.data_size)
// 		{
// 			ia_forward(net, &net->input.arr[j]);
// 			ia_backward(net, &net->input.arr[j], &net->output.arr[j]);
// 		}
// 		if (test)
// 			s = test(net);
// 		printf("%f %i \n", s, i + 1);
// 		ia_save(net, ft_itoa(s * 1000));
// 	}
// }

void	train_neuronal_network(t_net *net, t_data *data, int iteration)
{
	int		i;
	int		j;
	// double	s;

	i = -1;
	// s = 0;
	while (++i < iteration)
	{
		j = -1;
		while (++j < data->size)
		{
			ia_forward(net, &data->input.arr[j]);
			ia_backward(net, &data->input.arr[j], &data->output.arr[j]);
		}
		pbar("training the nn", i, iteration);
	}
}

void	train_test_neuronal_network(t_net *net, t_data *data, t_data *train, int iteration)
{
	int		i;
	int		j;
	double	s;
	t_v		rand;

	rand = v_range(0, data->size);
	i = -1;
	printf("%d %d %d\n", data->input.arr->size, data->output.arr->size, net->predicted_output.size);
	while (++i < iteration)
	{
		j = -1;
		s = 0;
		while (++j < data->size)
		{
			ia_forward(net, &data->input.arr[(int)rand.arr[j]]);
			ia_backward(net, &data->input.arr[(int)rand.arr[j]], &data->output.arr[(int)rand.arr[j]]);
			s += (v_maxi(&net->predicted_output) == v_maxi(&data->output.arr[j]));
		}
		test_neuronal_network(net, train);
		printf("\nusing the data of your neuronal network is %f%%\n", ((double)s / data->size) * 100);
		
		print_net(net);
	}
}

void	test_neuronal_network(t_net *net, t_data *data)
{
	int		j;
	double	s;


	s = 0;
	j = -1;
	while (++j < data->size)
	{
		ia_forward(net, &data->input.arr[j]);
		if (v_maxi(&net->predicted_output) == v_maxi(&data->output.arr[j]))
			s += 1;
		pbar("testing the data", j, data->size);
	}
	printf("\nthe accuracy of your neuronal network is %f%%\n", (s / data->size) * 100);
}
// ching chong
// -0.820995 : -0.791888 : -0.324696 : -0.286097 : 0.395708 : 0.224283 : -0.822446 : -0.877787 : -0.259817 : 0.085115 : -0.277291 : -0.272781 : 0.038447 : -0.863845 : 0.749287 : 0.740326 :