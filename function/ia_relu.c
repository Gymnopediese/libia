/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ia_relu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:35:11 by albaud            #+#    #+#             */
/*   Updated: 2023/03/07 23:13:08 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libia.h"

double	relu(double x)
{
	if (x > 0)
		return (x);
	return (0);
}

double	relu_prime(double x)
{
	if (x > 0)
		return (1);
	return (0);
}
