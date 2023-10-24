/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 01:25:40 by albaud            #+#    #+#             */
/*   Updated: 2023/10/25 01:44:58 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# define NSIZE 6
# define MNEURON 50

# include "../libia.h"
# include "../../mlx/struct.h"

typedef struct s_draw
{
	t_window	w;
	t_v			canvas;
	int			color;
	int			brush_size;
	int			pixel_size;
	int			x;
	int			y;
	double		min;
	void		(*key)();
}	t_draw;

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

void		visualize(t_vis *v, t_v *inp);
void		init_visualizer(t_vis *v, t_net *n);

void		synaps(t_vis *v, t_v *inp);
t_v2		ppose(int n, int i, int fsize, int dsize);
t_v2		spose(int n, int i, int fsize, int dsize);
void		visualize(t_vis *v, t_v *inp);

void		put_canvas(t_v *d, t_draw *draw);
int			key(int k, t_draw *draw);
int			up(int k, int a, int b, void *v);
int			down(int k, int a, int b, void *v);
int			draw(int x, int y, t_draw	*draw);
void		init_draw_canvas(t_draw	*res, int x, int y, int pixel_size);

#endif