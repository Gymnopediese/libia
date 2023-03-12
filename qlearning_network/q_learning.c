/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_learning.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:15:58 by albaud            #+#    #+#             */
/*   Updated: 2023/03/12 14:45:08 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libia.h"
#define MOVES 100000

int	get_action(t_net *net, t_v *inp, double exploration)
{
	if (rand_range(0, 1) < exploration)
		return (rand_range(0, net->info.outputs));
	ia_forward(net, inp);
	return (v_maxi(&net->predicted_output));
}

void	loss_function(t_net *net, t_v *inp, t_v *out, double qt)
{
	static t_v	b = (t_v){0, 0};

	if (b.size == 0)
		b = v_new(net->info.outputs, 0);
	ia_forward(net, inp);
	v_subn(&net->predicted_output, qt, &b);
	v_mult(&b, &b, &b);
	v_mult(&b, out, &b);
	ia_backward(net, inp, &b);
}

void	get_moves(t_agent *agent, t_move *moves, t_v *indexes, t_v2 *data)
{
	int	reward;
	t_v	inp;
	int	action;
	t_v	*temp;
	int	set_previous;

	reward = 0;
	agent->env.reset(agent->env.env);
	inp = v_new(agent->net.info.inputs, 0);
	temp = 0;
	set_previous = 0;
	while (reward != -1 && reward != 10)
	{
		agent->env.state(agent->env.env, &inp);
		action = get_action(&agent->net, &inp, data->y);
		reward = agent->env.step(agent->env.env, action);
		set_move(&moves[(int)indexes->arr[(int)data->x]],
			&inp, action, reward);
		if (set_previous++)
			moves[(int)indexes->arr[(int)data->x - 1]].next
				= &moves[(int)indexes->arr[(int)data->x]];
		data->x += 1;
		if (data->x >= MOVES)
			return ;
	}
}

void	print_move(t_move *move)
{
	v_xprint(move->input, 10);
	v_print(move->output);
	printf("%f\n", move->reward);
}

void	train_model(t_net *net, t_move *moves)
{
	int		i;
	double	qt;

	qt = 0;
	i = -1;
	while (++i < MOVES)
	{
		if (!moves[i].next)
			continue ;
		ia_forward(net, moves[i].next->input);
		qt = moves[i].reward + 0.99 * v_maxi(&net->predicted_output);
		loss_function(net, moves[i].input, moves[i].output, qt);
	}
}

void	q_learn(t_agent *agent, double exploration)
{
	t_move		moves[MOVES];
	t_v			indexes;
	t_v2		data;
	static int	max = -99;
	int			save;

	save = 0;
	indexes = v_range(0, MOVES);
	v_shuffle(&indexes);
	agent->env.reset(agent->env.env);
	data.x = 0;
	data.y = exploration;
	while (data.x < MOVES)
	{
		get_moves(agent, moves, &indexes, &data);
		if (max < agent->env.value(agent->env.env) && ++save)
			max = agent->env.value(agent->env.env);
	}
	train_model(&agent->net, moves);
	data.x = 0;
	while (++data.x < MOVES)
		free_move(&moves[(int)data.x]);
	free(indexes.arr);
	printf("max %i\n", max);
	if (save)
		ia_save(&agent->net, SAVE_INT, max);
}

void	q_learing(t_agent *agent, int iteration)
{
	int		i;
	double	exploration;

	i = -1;
	while (++i < iteration)
	{
		progressbar("learning", i, iteration);
		exploration = (double)(iteration - i * 2) / iteration;
		if (exploration < 0.1)
			exploration = 0.1;
		q_learn(agent, exploration);
	}
	progressbar("learning", i, iteration);
}
