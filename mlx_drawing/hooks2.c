/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:33:05 by albaud            #+#    #+#             */
/*   Updated: 2023/03/13 14:57:23 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libia.h"

int	*pressed(void)
{
	static int	pressed[1];

	return (pressed);
}

int	up(int k, int a, int b, void *v)
{
	(void) a;
	(void) b;
	(void) v;
	(void) k;
	*pressed() = 0;
	return (0);
}

void	draw_pixel(int x, int y, t_draw *draw, int assign)
{
	int	_x;
	int	_y;

	_x = -1;
	while (++_x < draw->brush_size)
	{
		_y = -1;
		while (++_y < draw->brush_size)
		{
			if (x + _x < draw->x * draw->pixel_size
				&& y + _y < draw->y * draw->pixel_size)
				draw->canvas.arr[(y / draw->pixel_size + _x)
					* draw->x + x / draw->pixel_size + _y]
					= assign;
		}
	}
}

int	draw(int x, int y, t_draw	*draw)
{
	if (!*pressed())
		return (0);
	if (*pressed() == 1)
		draw_pixel(x, y, draw, 1);
	else
		draw_pixel(x, y, draw, 0);
	draw_digits(&draw->canvas, draw);
	return (0);
}

int	down(int k, int a, int b, void *v)
{
	*pressed() = k;
	draw(a, b, v);
	return (0);
}
