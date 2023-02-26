/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_error.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:40:58 by albaud            #+#    #+#             */
/*   Updated: 2023/02/18 01:42:52 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vlib.h"

void	v_error(char *message)
{
	int	i;

	i = -1;
	write(2, "vlib: ", 6);
	while (message[++i])
		write(2, &message[i], 1);
	write(2, "\n", 1);
	exit(1);
}

void	v_stopif(t_v *a, char *msg, int (*f)(double))
{
	int	i;

	i = -1;
	while (++i < a->size)
	{
		if (f(a->arr[i]))
		{
			v_xprint(a, 20);
			v_error(msg);
		}
	}
}
