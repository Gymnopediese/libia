/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 22:16:05 by albaud            #+#    #+#             */
/*   Updated: 2023/02/25 00:09:43 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vlib.h"

void	swap(double *a, double *b)
{
	double	t;

	t = *a;
	*a = *b;
	*b = t;
}

void	set_seed(int i)
{
	srand(i);
}

double	rand_range(int min, int max)
{
	time_t		t;
	static int	innit = 1;
	double		res;
	double		deb;

	if (innit)
	{
		innit = 0;
		srand((unsigned) time(&t));
	}
	deb = (double)(rand() % (max - min) + min);
	res = (double)rand() / 10000000;
	res = (res - (int)res);
	return (deb + res);
}

int	rand_range_weight(int r, int ratio)
{
	double		res;
	int			i;
	int			m;
	double		tb;

	(void) ratio;
	res = rand_range(0, 1);
	i = -1;
	m = r * (r + 1) / 2;
	tb = 0;
	while (++i < r)
	{
		tb += (double)(r - i) / m;
		if (res < tb)
			return (i);
	}
	return ((int)tb);
}

void	v_shuffle(t_v *a)
{
	int	i;

	i = -1;
	while (++i < a->size)
		swap(&a->arr[i], &a->arr[(int)rand_range(i, a->size)]);
}
