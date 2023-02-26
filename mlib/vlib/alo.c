/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alo.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:30:39 by albaud            #+#    #+#             */
/*   Updated: 2023/02/23 15:31:12 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vlib.h"

void	*alo(int n, int size)
{
	void	*res;

	res = calloc(n, size);
	if (res == 0)
	{
		printf("libia: malloc error\n");
		exit(1);
	}
	return (res);
}
