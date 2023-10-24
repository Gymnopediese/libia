/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 23:00:13 by albaud            #+#    #+#             */
/*   Updated: 2023/10/24 12:45:12 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libia.h"

#if __has_include("../../mlx/minilibx.h") && __has_include(<stdint.h>)

t_v2	ppose(int n, int i, int fsize, int dsize)
{
	if (dsize > MNEURON)
		dsize = MNEURON;
	return ((t_v2){
		200 * n + 100,
		i * (NSIZE * 2 + 3) + NSIZE * (fsize - dsize),
	});
}

t_v2	spose(int n, int i, int fsize, int dsize)
{
	if (dsize > MNEURON)
		dsize = MNEURON;
	return ((t_v2){
		(200 * n + 100) + NSIZE,
		(i * (NSIZE * 2 + 3) + NSIZE * (fsize - dsize)) + NSIZE,
	});
}
#endif