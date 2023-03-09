/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:12:27 by albaud            #+#    #+#             */
/*   Updated: 2023/02/14 20:27:50 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cfiles.h"

void	ft_atoia_fast(char *str, char split, double *buffer, int div)
{
	int		i;
	int		k;

	i = -1;
	k = -1;
	while (str[++k])
	{
		buffer[++i] = ft_atodo(&str[k]) / div;
		while (str[++k] && str[k] != split)
			;
	}
}
