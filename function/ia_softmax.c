/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ia_softmax.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:56:37 by albaud            #+#    #+#             */
/*   Updated: 2023/10/23 17:57:35 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libia.h"

double	softmax(double x)
{
	return (exp(x) / (exp(x) + 1));
}

double	softmax_prime(double x)
{
	return (softmax(x) * (1 - softmax(x)));
}
