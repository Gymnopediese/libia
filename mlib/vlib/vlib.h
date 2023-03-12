/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vlib.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:06:06 by albaud            #+#    #+#             */
/*   Updated: 2023/03/10 12:13:01 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VLIB_H
# define VLIB_H

# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <time.h>
# include <stdio.h>
# include "t_v.h"

int		v_tocol(double r, double g, double b);
t_v		v_new(int size, double init);
void	v_error(char *message);
double	v_max(t_v *a);
double	v_dot(t_v *a, t_v *b);
t_v		v_rand(int size, int min, int max);
double	v_dist(t_v *a, t_v *b);
double	v_omax(t_v *a);
int		v_maxi(t_v *a);
void	v_copy(t_v *dest, t_v *src);
double	v_min(t_v *a);
int		v_mini(t_v *a);
double	v_sum(t_v *a);
void	v_apply(t_v *a, double (*f)(double));
void	v_stopif(t_v *a, char *msg, int (*f)(double));
void	v_xprint(t_v *a, int x);
void	v_print(t_v *a);
void	v_mprint(t_v *a, int x);
void	v_clear(t_v *a, double init);
void	v_add(t_v *a, t_v *b, t_v *res);
void	v_addn(t_v *a, double d);
void	v_add_a_x_b(t_v *a, double b, t_v *res);
void	v_subs(t_v *a, t_v *b, t_v *res);
void	v_mult(t_v *a, t_v *b, t_v *res);

void	*alo(int n, int size);
t_v		v_range(int min, int max);
void	swap(double *a, double *b);
void	v_shuffle(t_v *a);
double	rand_range(int min, int max);
int		rand_range_weight(int r, int ratio);
void	set_seed(int i);
void	v_subn(t_v *a, double b, t_v *res);

#endif