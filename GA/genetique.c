/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   genetique.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:34:25 by albaud            #+#    #+#             */
/*   Updated: 2023/03/11 12:21:19 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libia.h"
#define POPSIZE 3000
#define MOVES_AMOUNT 30000

t_run	random_game(t_agent *agent)
{
	int		r;
	t_run	res;
	t_v		inp;
	int		st;
	int		m;

	inp = v_new(agent->net.info.inputs, 0);
	res.head = 0;
	res.size = 0;
	res.score = 0;
	m = 0;
	agent->env.reset(agent->env.env);
	while (1)
	{
		agent->env.state(agent->env.env, &inp);
		st = (int)rand_range(0, 4);
		r = agent->env.step(agent->env.env, st);
		add_move(&res, &inp, st, r);
		if (r == 1)
			m = 0;
		if (r == -1 || ++m >= 50)
		{
			res.score = agent->env.value(agent->env.env);
			break ;
		}
	}
	return (res);
}

t_run	neuron_game(t_agent *ag, int i)
{
	int		r;
	t_run	res;
	t_v		inp;
	int		st;
	int		m;

	inp = v_new(ag->net.info.inputs, 0);
	res.head = 0;
	res.size = 0;
	m = 0;
	i = i * 5 + 10;
	if (i > 100)
		i = 100;
	ag->env.reset(ag->env.env);
	while (1)
	{
		ag->env.state(ag->env.env, &inp);
		st = get_action(&ag->net, &inp, 0.05);
		r = ag->env.step(ag->env.env, st);
		if (r == 1)
			m = 0;
		if (r == -1 || r == 10 || ++m >= i)
		{
			res.score = ag->env.value(ag->env.env);
			break ;
		}
		add_move(&res, &inp, st, r);
	}
	return (res);
}

void	sort_runs(t_run *runs)
{
	int		f;
	int		j;
	t_run	t;

	f = 1;
	while (f)
	{
		f = 0;
		j = -1;
		while (++j < POPSIZE - 1)
		{
			if (runs[j].score < runs[j + 1].score)
			{
				t = runs[j];
				runs[j] = runs[j + 1];
				runs[j + 1] = t;
				f = 1;
			}
		}
	}
}

void	resort_runs(t_run *runs)
{
	int		f;
	int		j;
	t_run	t;

	f = 1;
	while (f)
	{
		f = 0;
		j = -1;
		while (++j < POPSIZE - 1)
		{
			if (runs[j].size > runs[j + 1].size
				&& runs[j].score == runs[j + 1].score)
			{
				t = runs[j];
				runs[j] = runs[j + 1];
				runs[j + 1] = t;
				f = 1;
			}
		}
	}
}

void	learn(t_agent *g, t_run *runs)
{
	int		f;
	int		j;
	t_move	*m;
	t_move	*moves[MOVES_AMOUNT];
	t_v		rand;

	rand = v_range(0, MOVES_AMOUNT);
	v_shuffle(&rand);
	sort_runs(runs);
	resort_runs(runs);
	printf("mmmm %i %i\n", runs[0].score, runs[0].size);
	j = -1;
	while (j < MOVES_AMOUNT)
	{
		f = rand_range_weight(POPSIZE, 10) / 30;
		m = runs[f].head;
		while (m)
		{
			if (j >= MOVES_AMOUNT - 1)
				break ;
			moves[(int)rand.arr[++j]] = m;
			m = m->next;
		}
		if (j >= MOVES_AMOUNT - 1)
			break ;
	}
	j = -1;
	while (++j < MOVES_AMOUNT)
	{
		ia_forward(&g->net, moves[j]->input);
		ia_backward(&g->net, moves[j]->input, moves[j]->output);
	}
}

void	free_runs(t_run	*runs)
{
	int	i;

	i = -1;
	while (++i < POPSIZE)
		free_run(runs);
}

void	ga_train(t_agent *agent, int generations, int r)
{
	int		i;
	int		j;
	t_run	population[POPSIZE];
	t_run	children[POPSIZE];

	i = -1;
	if (!r)
	{
		while (++i < POPSIZE)
			population[i] = random_game(agent);
	}
	else
	{
		while (++i < POPSIZE)
			population[i] = neuron_game(agent, 10);
	}
	i = -1;
	while (++i < generations)
	{
		progressbar("generationing :)", i, generations);
		net_clear(&agent->net);
		learn(agent, population);
		ia_save(&agent->net, SAVE_INT, population[0].score);
		j = -1;
		while (++j < POPSIZE)
			children[j] = neuron_game(agent, i + 10 * r);
		free_runs(population);
		j = -1;
		while (++j < POPSIZE)
			population[j] = children[j];
	}
	progressbar("generationing :)", i, generations);
}
