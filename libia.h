/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libia.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 01:25:40 by albaud            #+#    #+#             */
/*   Updated: 2023/10/24 11:35:34 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBIA_H
# define LIBIA_H

# define NSIZE 6
# define MNEURON 50

# include <stdarg.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>
# include <math.h>
# include <pthread.h>
# include <stdio.h>
// # include "p/p.h"
// # include "mlib/mlib.h"
// # include "koflibc/sources.h"
# include "../libalbaud.h"
// # include "cfiles/cfiles.h"
# define MINMAXRAND 0.5

typedef void	(*t_voidf)();
typedef int		(*t_intf)();
typedef double	(*t_doublef)();
typedef double	(*t_doublefd)(double);

enum
{
	FUNCTION_SIGMOID,
	FUNCTION_RELU,
	FUNCTION_TANH,
	FUNCTION_SOFTMAX,
	FUNCTION_NONE
};

// char	*name;
// int		inputs;
// int		hiden_layers;
// int		*hiden_layers_size;
// int		outputs;
// double	(*function)(double);
// double	(*function_prime)(double);
typedef struct s_info
{
	char	*name;

	double	learning;
	int		inputs;
	int		hiden_layers;
	int		*hiden_layers_size;
	int		outputs;

	int		function;

}	t_info;

typedef struct s_net
{
	t_info	info;

	t_v		*hiden;
	t_v		*bias;
	t_v		predicted_output;

	t_v		*delta_hiden;
	t_v		delta_output;

	t_m		*weights;

	double	(*function)(double);
	double	(*function_prime)(double);

}	t_net;

typedef struct s_move
{
	struct s_move	*next;
	t_v				*input;
	t_v				*output;
	double			reward;
}	t_move;

typedef struct s_run
{
	t_move	*head;
	t_move	*tail;
	int		size;
	int		score;
}	t_run;

// void		*env;
// int		(*step)();
// void		(*reset)();
// void		(*draw)();
// void		(*state)();
// double	(*value)();

// typedef struct s_env t_env;

typedef struct s_env
{
	void		*env;
	int			(*step)(struct s_env *, int move);
	void		(*reset)(struct s_env *);
	void		(*draw)(struct s_env *);
	void		(*state)(struct s_env *, t_v *input);
	double		(*value)(struct s_env *);
}	t_env;

# if __has_include("../mlx/minilibx.h") && __has_include(<stdint.h>)
#  include "mlx_drawing/graphics.h"
# endif

typedef struct s_agent
{
	t_net		net;
	t_env		env;
# ifdef GRAPHICS_H
	t_vis		vis;
# endif
}	t_agent;

typedef struct s_data
{
	t_m		input;
	t_m		output;
	int		size;
}	t_data;

typedef struct s_gan
{
	t_net		inspector;
	t_net		generator;
	t_data		data;
# ifdef GRAPHICS_H
	t_vis		vinspector;
	t_vis		vgenerator;
	t_draw		draw;
# endif

}	t_gan;

// void		*env;
// int		(*step)();
// void		(*reset)();
// void		(*draw)();
// void		(*state)();
t_env		init_env(void *env, ...);
void 		print_net(t_net *net);
// char	*name;
// int		inputs_size;
// int		hiden_layers_amount;
// int		*hiden_layers_size;
// int		outputs_size;
// double	(*function)(double);
// double	(*function_prime)(double);
void		init_neuronal_network(t_net *res, t_info infos);
void		free_move(t_move *m);
void		set_move(t_move *move, t_v *state, int action, double reward);

void		ia_forward(t_net *net, const t_v *input);
void		ia_backward(t_net *net, t_v *input, t_v *output);
void		ia_pforward(t_net *net, t_v *input);
void		ia_random_train(t_net *net, int n);
void		ia_train_test(t_net *net, int n, double (*test)(t_net *));
void		ia_save(const t_net *net, ...);
t_net		ia_load(char *filename);
void		net_clear(t_net *net);
double		ia_k_voisins(t_m *input, t_v *output, t_v *guess, int v);
double		ia_k_voisins_om(t_m *input, t_m *output, t_v *guess, int v);
void		atoia(double *res, char *str, char *split);
void		q_learing(t_agent *agent, int iteration);
double		relu(double x);
double		relu_prime(double x);
double		sigmoid(double x);
double		sigmoid_prime(double x);
double		softmax(double x);
double		softmax_prime(double x);
double		tanh_prime(double x);
void		free_run(t_run	*run);
void		add_move(t_run *r, t_v *state, int action, double reward);
void		ga_train(t_agent *agent, int generations, int r);
int			ia_predict(t_net *net, const t_v *input);
int			get_action(t_net *net, t_v *inp, double exploration);

t_gan		init_gan(void);
void		train_gan(t_gan *gan, int iter);
void		train_test_neuronal_network(t_net *net, t_data *data, t_data *train, int iteration);

//read a file of formate : <start> line to skip: input {0, 1, 2, 3, 4, etc}: input 
t_data		read_data(char *path, int inp_size, int out_size, int start);
t_data		read_csv_file(char *path, int inp_size, int out_size, int start, int length);
void		train_neuronal_network(t_net *net, t_data *data, int iteration);
double		test_neuronal_network(t_net *net, t_data *data);
void		set_function(t_net *res);

void		m_stuff(t_m *m, const t_v *a, const t_v *b, const double learning);
void		propagation(t_m *weights, t_v *hiden, t_v *right, t_v *left, t_net *net);
void		v_addapply(t_v *a, const t_v *b, double (*f)(double));
#endif