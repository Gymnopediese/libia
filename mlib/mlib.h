/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlib.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:06:06 by albaud            #+#    #+#             */
/*   Updated: 2023/02/27 00:46:03 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLIB_H

# define MLIB_H

# include "t_mtx.h"
# include "stdio.h"

//return a new vector o
t_mtx	m_new(int x, int y, int init);
t_mtx	m_rand(int x, int y, int min, int max);

double	m_max(t_mtx *a);
//apply to res the dot product of a and b, clear res
void	m_dot(t_mtx *a, t_mtx *b, t_mtx *res);
void	m_clear(t_mtx *a, int num);
void	m_apply(t_mtx *a, double (*f)(double));

void	m_print(t_mtx *mtx);
void	m_add(t_mtx *a, t_mtx *b, t_mtx *res);
void	m_mult(t_mtx *a, t_mtx *b, t_mtx *res);
void	m_subs(t_mtx *a, t_mtx *b, t_mtx *res);
void	m_hvdot(t_mtx *a, t_v *b, t_v *res);
void	m_vvdot(t_mtx *a, t_v *b, t_v *res);

#endif