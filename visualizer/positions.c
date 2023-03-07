/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 23:00:13 by albaud            #+#    #+#             */
/*   Updated: 2023/03/07 23:43:26 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libia.h"

t_vector	ppose(int n, int i, int fsize, int dsize)
{
	if (dsize > MNEURON)
		dsize = MNEURON;
	return ((t_vector){
		200 * n + 100,
		i * (NSIZE * 2 + 3) + NSIZE * (fsize - dsize),
		0,
		0,
	});
}

t_vector	spose(int n, int i, int fsize, int dsize)
{
	if (dsize > MNEURON)
		dsize = MNEURON;
	return ((t_vector){
		(200 * n + 100) + NSIZE,
		(i * (NSIZE * 2 + 3) + NSIZE * (fsize - dsize)) + NSIZE,
		0,
		0,
	});
}
