/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_dot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:26:23 by albaud            #+#    #+#             */
/*   Updated: 2023/03/07 22:42:31 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlib.h"
#include "mlib.h"

void	ia_dot_matrix_fuck_off(t_mtx *a, t_mtx *b, t_mtx *res)
{
	int		x;
	int		y;
	int		z;

	x = -1;
	while (++x < a->size)
	{
		y = -1;
		while (++y < a->arr[0].size)
		{
			z = -1;
			while (++z < b->arr[0].size)
			{
				res->arr[y].arr[z] += a->arr[x].arr[y] * b->arr[x].arr[z];
			}
		}
	}
}

void	ia_dot_matrix_fuck(t_mtx *a, t_mtx *b, t_mtx *res)
{
	int		x;
	int		y;
	int		z;

	x = -1;
	while (++x < a->size)
	{
		y = -1;
		while (++y < a->arr[0].size)
		{
			z = -1;
			while (++z < b->size)
			{
				res->arr[x].arr[z] += a->arr[x].arr[y] * b->arr[z].arr[y];
			}
		}
	}
}

void	m_dot(t_mtx *a, t_mtx *b, t_mtx *res)
{
	int		x;
	int		y;
	int		z;

	m_clear(res, 0);
	if (b->size != a->arr[0].size)
	{
		if (b->size == a->size)
			ia_dot_matrix_fuck_off(a, b, res);
		else
			ia_dot_matrix_fuck(a, b, res);
		return ;
	}
	x = -1;
	while (++x < a->size)
	{
		y = -1;
		while (++y < a->arr[0].size)
		{
			z = -1;
			while (++z < b->arr[0].size)
				res->arr[x].arr[z] += a->arr[x].arr[y] * b->arr[y].arr[z];
		}
	}
}
