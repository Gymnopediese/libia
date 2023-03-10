/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 00:27:18 by albaud            #+#    #+#             */
/*   Updated: 2023/03/13 21:58:45 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libia.h"

void	draw_digits(t_v *d, t_draw *draw)
{
	int	x;
	int	y;

	x = -1;
	ft_clean_canvas(draw->w.cvs);
	while (++x < draw->x)
	{
		y = -1;
		while (++y < draw->y)
		{
			if (d->arr[y * 28 + x] > draw->min)
				ft_draw_fsquare(&draw->w.cvs,
					(t_vector){x * draw->pixel_size,
					y * draw->pixel_size, 0, 0},
					draw->pixel_size, v_tocol(d->arr[y * draw->x + x] * 255,
						d->arr[y * draw->x + x] * 255, d->arr[y * draw->x + x]
						* 255));
		}
	}
	ft_putimg(draw->w, draw->w.cvs.img, (t_vector){0, 0, 0, 0});
}

void	init_draw_canvas(t_draw	*res, int x, int y, int pixel_size)
{
	res->brush_size = 1;
	res->pixel_size = pixel_size;
	res->x = x;
	res->y = y;
	ft_mlx_init(&res->w, x * pixel_size, y * pixel_size, "DRAWING CANVAS");
	res->canvas = v_new(x * y, 0);
	res->w.cvs = ft_init_filled_canvas(&res->w.mlx,
			pixel_size * x, pixel_size * y, 0);
	mlx_hook(res->w.win, 4, 0, down, res);
	mlx_hook(res->w.win, 5, 0, up, 0);
	mlx_hook(res->w.win, 6, 0, draw, res);
	res->min = 0;
}

int	key(int k, t_draw *draw)
{
	if (k == KEYCODE_SPACE)
		v_clear(&draw->canvas, 0);
	if (k == KEYCODE_1)
		draw->brush_size++;
	if (k == KEYCODE_2 && draw->brush_size > 1)
		draw->brush_size--;
	if (k == KEYCODE_3 && draw->min < 1)
		draw->min += 0.05;
	if (k == KEYCODE_4 && draw->min > 0.05)
		draw->min -= 0.05;
	draw_digits(&draw->canvas, draw);
	return (0);
}
