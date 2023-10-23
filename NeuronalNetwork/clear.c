/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:58:24 by albaud            #+#    #+#             */
/*   Updated: 2023/10/23 16:59:03 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libia.h"

double	randomdouble(double c)
{
	(void) c;
	return (randdouble(-MINMAXRAND, MINMAXRAND));
}

void	net_clear(t_net *net)
{
	int	i;

	i = -1;
	while (++i)
	{
		m_apply(&net->weights[i], randomdouble);
		v_apply(&net->bias[i], randomdouble);
	}
}
