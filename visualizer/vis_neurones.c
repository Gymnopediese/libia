/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_neurones.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 23:09:50 by albaud            #+#    #+#             */
/*   Updated: 2023/09/27 15:57:31 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libia.h"

void	_vis_inp(t_vis *v, t_v *inp)
{
	int	i;

	i = -1;
	while (++i < inp->size && i < MNEURON)
	{
		if (inp->arr[i] > 0.5)
			ft_putimg(v->w, v->on.img, ppose(0, i, v->y, inp->size));
		else
			ft_putimg(v->w, v->off.img, ppose(0, i, v->y, inp->size));
	}
}

int	_vis_hiden(t_vis *v)
{
	int	i;
	int	k;

	k = -1;
	while (++k < v->n->info.hiden_layers)
	{
		i = -1;
		while (++i < v->n->hiden[k].size && i < MNEURON)
		{
			if (v->n->hiden[k].arr[i] > 0.5)
				ft_putimg(v->w, v->on.img,
					ppose(k + 1, i, v->y, v->n->hiden[k].size));
			else
				ft_putimg(v->w, v->off.img,
					ppose(k + 1, i, v->y, v->n->hiden[k].size));
		}
	}
	return (k);
}

void	_vis_out(t_vis *v, int k)
{
	int	i;

	i = -1;
	while (++i < v->n->predicted_output.size && i < MNEURON)
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

void	visualize(t_vis *v, t_v *inp)
{
	int	k;

	mlx_clear_window(v->w.mlx, v->w.win);
	synaps(v, inp);
	_vis_inp(v, inp);
	k = _vis_hiden(v);
	_vis_out(v, k);
}
