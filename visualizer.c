/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 12:03:19 by albaud            #+#    #+#             */
/*   Updated: 2023/02/26 20:06:06 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libia.h"

#define NSIZE 10
#define MNEURON 50

t_vector	ppose(int n, int i, int fsize, int dsize)
{
	return ((t_vector){
		200 * n + 100,
		i * (NSIZE * 2 + 3) + NSIZE * (fsize - dsize),
		0,
		0,
	});
}

t_vector	spose(int n, int i, int fsize, int dsize)
{
	return ((t_vector){
		(200 * n + 100) + NSIZE,
		(i * (NSIZE * 2 + 3) + NSIZE * (fsize - dsize)) + NSIZE,
		0,
		0,
	});
}

void	synaps(t_vis *v, t_v *inp)
{
	int	i;
	int	f;
	int	k;

	ft_clean_canvas(v->w.cvs);
	i = -1;
	while (++i < inp->size)
	{
		f = -1;
		while (++f < v->n->hiden[0].size)
		{
			if (v->n->hiden[0].arr[f] > 0.5 && inp->arr[i] > 0.5)
				ft_draw_line(&v->w.cvs, spose(0, i, v->y, inp->size),
					spose(1, f, v->y, v->n->hiden[0].size), WHITE);
		}
	}
	k = -1;
	while (++k < v->n->info.hiden_layers - 1)
	{
		i = -1;
		while (++i < v->n->hiden[k].size)
		{
			f = -1;
			while (++f < v->n->hiden[k + 1].size)
			{
				if (v->n->hiden[k].arr[i] > 0.5
					&& v->n->hiden[k + 1].arr[f] > 0.5)
					ft_draw_line(&v->w.cvs, spose(k + 1, i, v->y, v->n->hiden[k].size),
						spose(k + 2, f, v->y, v->n->hiden[k + 1].size), WHITE);
			}
		}
	}
	i = -1;
	while (++i < v->n->hiden[k].size)
	{
		if (v->n->hiden[k].arr[i] > 0.5)
			ft_draw_line(&v->w.cvs, spose(k + 1, i, v->y, v->n->hiden[k].size),
				spose(k + 2, v_maxi(&v->n->predicted_output),
				v->y, v->n->predicted_output.size), WHITE);
	}
	ft_putimg(v->w, v->w.cvs.img, (t_vector){0, 0, 0, 0});
}


void	visualize(t_vis *v, t_v *inp)
{
	int	i;
	int	k;

	i = -1;
	mlx_clear_window(v->w.mlx, v->w.win);
	synaps(v, inp);
	while (++i < inp->size)
	{
		if (inp->arr[i] > 0.5)
			ft_putimg(v->w, v->on.img, ppose(0, i, v->y, inp->size));
		else
			ft_putimg(v->w, v->off.img, ppose(0, i, v->y, inp->size));
	}
	k = -1;
	while (++k < v->n->info.hiden_layers)
	{
		i = -1;
		while (++i < v->n->hiden[k].size)
		{
			if (v->n->hiden[k].arr[i] > 0.5)
				ft_putimg(v->w, v->on.img,
					ppose(k + 1, i, v->y, v->n->hiden[k].size));
			else
				ft_putimg(v->w, v->off.img,
					ppose(k + 1, i, v->y, v->n->hiden[k].size));
		}
	}
	i = -1;
	while (++i < v->n->predicted_output.size)
	{
		if (v_maxi(&v->n->predicted_output) == i)
			ft_putimg(v->w, v->on.img,
				ppose(k + 1, i, v->y, v->n->predicted_output.size));
		else
			ft_putimg(v->w, v->off.img,
				ppose(k + 1, i, v->y, v->n->predicted_output.size));
		if (v->out_label)
		{
			mlx_string_put(v->w.mlx, v->w.win,
				ppose(k + 1, i, v->y, v->n->predicted_output.size).x + 50,
				ppose(k + 1, i, v->y, v->n->predicted_output.size).y, WHITE,
				v->out_label[i]);
		}
			
	}
}

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
	ft_mlx_init(&v->w, (n->info.hiden_layers + 2) * 200 + 100, num * (NSIZE * 2 + 3), "NN VISUALIZER");
	v->w.cvs = ft_init_canvas(v->w.mlx, (n->info.hiden_layers + 2) * 200, num * (NSIZE * 2 + 3));
	v->on = ft_init_circle_canvas(v->w.mlx, NSIZE, WHITE);
	v->off = ft_init_circle_canvas(v->w.mlx, NSIZE, WHITE);
	ft_draw_circle(&v->on, NSIZE * 4 / 5, RED);
	ft_draw_circle(&v->off, NSIZE * 4 / 5, BLUE);
	pthread_create(&v->t, 0, visloop, v);
}
