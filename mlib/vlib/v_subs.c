/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_subs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:59:49 by albaud            #+#    #+#             */
/*   Updated: 2023/03/10 11:59:49 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vlib.h"

void	v_subs(t_v *a, t_v *b, t_v *res)
{
	int		ite;

	ite = -1;
	while (++ite < a->size)
		res->arr[ite] = a->arr[ite] - b->arr[ite];
}

void	v_subn(t_v *a, double b, t_v *res)
{
	int		ite;

	ite = -1;
	while (++ite < a->size)
		res->arr[ite] = a->arr[ite] - b;
}
