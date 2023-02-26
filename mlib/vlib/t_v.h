/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_v.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:06:06 by albaud            #+#    #+#             */
/*   Updated: 2023/02/16 17:33:17 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_V_H
# define T_V_H 2

typedef struct s_n
{
	double		n;
	struct s_n	*next;
}	t_n;

typedef struct s_s
{
	int	size;
	t_n	*first;
	t_n	*last;
}	t_s;

typedef struct s_v
{
	double	*arr;
	int		size;
}	t_v;

#endif