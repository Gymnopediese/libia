/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_tocol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:33:43 by albaud            #+#    #+#             */
/*   Updated: 2023/02/21 10:34:01 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vlib.h"

int	v_tocol(double r, double g, double b)
{
	int	rgb;

	if (r >= 255.0)
		rgb = 255;
	else
		rgb = r;
	if (g >= 255.0)
		rgb = (rgb << 8) + 255;
	else
		rgb = (rgb << 8) + g;
	if (b >= 255.0)
		rgb = (rgb << 8) + 255;
	else
		rgb = (rgb << 8) + b;
	return (rgb);
}
