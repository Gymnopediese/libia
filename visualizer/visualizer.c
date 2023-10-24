/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 12:03:19 by albaud            #+#    #+#             */
/*   Updated: 2023/10/24 12:45:40 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libia.h"

#if __has_include("../../mlx/minilibx.h") && __has_include(<stdint.h>)

void	*visloop(void	*vv)
{
	t_vis	*vis;

	vis = vv;
	mlx_loop(vis->w.mlx);
	return (0);
}

void	init_visualizer(t_vis *v, t_net *n)
{
	int	num;

	num = n->info.inputs;
	if (n->info.hiden_layers_size[0] > num)
		num = n->info.hiden_layers_size[0];
	if (n->info.outputs > num)
		num = n->info.outputs;
	if (num > MNEURON)
		num = MNEURON;
	v->n = n;
	v->x = n->info.hiden_layers + 2;
	v->y = num;
	v->inp_label = 0;
	v->out_label = 0;
	ft_mlx_init(&v->w, (n->info.hiden_layers + 2)
		* 200 + 100, num * (NSIZE * 2 + 3), "NN VISUALIZER");
	v->w.cvs = ft_init_canvas(v->w.mlx,
			(n->info.hiden_layers + 2) * 200, num * (NSIZE * 2 + 3));
	v->on = ft_init_circle_canvas(v->w.mlx, NSIZE, WHITE);
	v->off = ft_init_circle_canvas(v->w.mlx, NSIZE, WHITE);
	ft_draw_circle(&v->on, NSIZE * 4 / 5, RED);
	ft_draw_circle(&v->off, NSIZE * 4 / 5, BLUE);
	pthread_create(&v->t, 0, visloop, v);
}
#endif