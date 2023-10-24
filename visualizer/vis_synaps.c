/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_synaps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 23:02:04 by albaud            #+#    #+#             */
/*   Updated: 2023/10/24 12:45:27 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libia.h"

#if __has_include("../../mlx/minilibx.h") && __has_include(<stdint.h>)

void	_vis_syn_inp(t_vis *v, t_v *inp)
{
	int	i;
	int	f;

	i = -1;
	while (++i < inp->size && i < MNEURON)
	{
		f = -1;
		while (++f < v->n->hiden[0].size && f < MNEURON)
		{
			if (v->n->hiden[0].arr[f] > 0.5 && inp->arr[i] > 0.5)
				ft_draw_line(&v->w.cvs, spose(0, i, v->y, inp->size),
					spose(1, f, v->y, v->n->hiden[0].size), WHITE);
		}
	}
}

int	_vis_syn_hiden(t_vis *v)
{
	int	i;
	int	f;
	int	k;

	k = -1;
	while (++k < v->n->info.hiden_layers - 1)
	{
		i = -1;
		while (++i < v->n->hiden[k].size && i < MNEURON)
		{
			f = -1;
			while (++f < v->n->hiden[k + 1].size && f < MNEURON)
			{
				if (v->n->hiden[k].arr[i] > 0.5
					&& v->n->hiden[k + 1].arr[f] > 0.5)
					ft_draw_line(&v->w.cvs, spose(k + 1,
							i, v->y, v->n->hiden[k].size),
						spose(k + 2, f, v->y, v->n->hiden[k + 1].size), WHITE);
			}
		}
	}
	return (k);
}

void	_vis_syn_out(t_vis *v, int k)
{
	int	i;

	i = -1;
	while (++i < v->n->hiden[k].size && i < MNEURON)
	{
		if (v->n->hiden[k].arr[i] > 0.5)
			ft_draw_line(&v->w.cvs, spose(k + 1, i, v->y, v->n->hiden[k].size),
				spose(k + 2, v_maxi(&v->n->predicted_output),
					v->y, v->n->predicted_output.size), WHITE);
	}
}

void	synaps(t_vis *v, t_v *inp)
{
	int	k;

	ft_clean_canvas(v->w.cvs);
	_vis_syn_inp(v, inp);
	k = _vis_syn_hiden(v);
	_vis_syn_out(v, k);
	ft_putimg(v->w, v->w.cvs.img, (t_v2){0, 0});
}
#endif