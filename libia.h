/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libia.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 01:25:40 by albaud            #+#    #+#             */
/*   Updated: 2023/02/26 14:57:19 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBIA_H
# define LIBIA_H

# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>
# include <math.h>
# include <pthread.h>
# include <stdio.h>
# include "../p/p.h"
# include "../cfiles/cfiles.h"
# include "mlib/mlib.h"


typedef struct s_info
{
	int		inputs;
	int		hiden_layers;
	int		*hiden_layers_size;
	int		outputs;
	int		data_size;
}	t_info;

typedef struct s_net
{
	t_info	info;

	t_mtx	input;
	t_mtx	output;
	t_v		*hiden;
	t_v		*bias;
	t_v		predicted_output;

	t_v		*delta_hiden;
	t_v		delta_output;

	t_mtx	*weights;

	char	*name;
}	t_net;

typedef struct s_vis
{
	t_window	w;
	t_net		*n;
	pthread_t	t;
	t_canvas	on;
	t_canvas	off;
	int			x;
	int			y;
	char		**inp_label;
	char		**out_label;
}	t_vis;

typedef struct s_data
{
	t_v	input;
	t_v	hiden;
	t_v	output;
}	t_data;

void	*alo(int n, int size);
void	ia_forward(t_net *net, t_v *input);
void	ia_backward(t_net *net, t_v *input, t_v *output);
void	ia_pforward(t_net *net, t_v *input);
t_net	*ia_init_net(t_net *res, char *name, t_info *info);
void	ia_random_train(t_net *net, int n);
void	ia_train_test(t_net *net, int n, double (*test)(t_net *));
void	ia_save(const t_net *net, char *name);
void	net_clear(t_net *net);
void	ia_load(t_net *net, char *name);
double	ia_k_voisins(t_mtx *input, t_v *output, t_v *guess, int v);
double	ia_k_voisins_om(t_mtx *input, t_mtx *output, t_v *guess, int v);

double	relu(double x);
double	relu_prime(double x);
double	sigmoid(double x);
double	sigmoid_prime(double x);

void	visualize(t_vis *v, t_v *inp);
void	init_visualizer(t_vis *v, t_net *n);
#endif