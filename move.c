/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:11:20 by albaud            #+#    #+#             */
/*   Updated: 2023/03/11 10:47:55 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libia.h"

void	free_move(t_move *m)
{
	free(m->input->arr);
	free(m->output->arr);
	free(m->input);
	free(m->output);
}

void	free_run(t_run	*run)
{
	t_move	*m;
	t_move	*t;

	m = run->head;
	while (m)
	{
		t = m->next;
		free_move(m);
		free(m);
		m = t;
	}
	run->head = 0;
	run->tail = 0;
	run->size = 0;
}

// void	free_runs(t_run *runs)
// {
// 	int		i;

// 	i = 0;
// 	while (++i < POPSIZE)
// 		free_move(&runs[i]);
// }

//t_move *move
//t_v *state
//int action
//double reward
void	set_move(t_move *move, t_v *state, int action, double reward)
{
	move->input = alo(1, sizeof(t_v));
	move->output = alo(1, sizeof(t_v));
	*move->input = v_new(state->size, 0);
	*move->output = v_new(4, 0);
	v_copy(move->input, state);
	move->output->arr[action] = 1;
	move->reward = reward;
	move->next = 0;
}

void	add_move(t_run *r, t_v *state, int action, double reward)
{
	t_move	*nb;

	nb = alo(1, sizeof(t_move));
	nb->input = alo(1, sizeof(t_v));
	nb->output = alo(1, sizeof(t_v));
	*nb->input = v_new(state->size, 0);
	*nb->output = v_new(4, 0);
	v_copy(nb->input, state);
	nb->output->arr[action] = 1;
	nb->reward = reward;
	nb->next = 0;
	if (r->head == 0)
	{
		r->head = nb;
		r->tail = nb;
		r->score = 0;
		r->size = 0;
	}
	else
	{
		r->tail->next = nb;
		r->tail = nb;
	}
	r->size += 1;
}
