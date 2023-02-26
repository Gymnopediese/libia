/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 23:54:43 by albaud            #+#    #+#             */
/*   Updated: 2023/02/24 19:29:52 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vlib.h"

void	v_mprint(t_v *a, int x)
{
	int		ite;

	ite = -1;
	while (++ite < a->size)
	{
		printf("%f : ", a->arr[ite]);
		if ((ite + 1) % x == 0)
			printf("\n");
	}
	if ((ite + 1) % x != 0)
		printf("\n");
}

void	v_print(t_v *a)
{
	int		ite;

	ite = -1;
	while (++ite < a->size)
		printf("%f : ", a->arr[ite]);
	printf("\n");
}

void	v_xprint(t_v *a, int x)
{
	int		ite;

	ite = -1;
	while (++ite < a->size && ite < x)
		printf("%f : ", a->arr[ite]);
	printf("\n");
}
