/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_apply.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:19:19 by albaud            #+#    #+#             */
/*   Updated: 2023/02/17 13:03:23 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vlib.h"

void	v_apply(t_v *a, double (*f)(double))
{
	int		ite;

	ite = -1;
	while (++ite < a->size)
		a->arr[ite] = f(a->arr[ite]);
}
