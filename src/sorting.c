/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:36:16 by vbonnard          #+#    #+#             */
/*   Updated: 2025/02/03 13:45:49 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_move(t_move *temp, t_move move, int *best)
{
	int	cost;

	cost = move.nb_ra + move.nb_rb + move.nb_rra + move.nb_rrb;
	if (cost < *best)
	{
		*temp = move;
		*best = cost;
	}
}

void	best_move(t_move *move)
{
	int		best;
	t_move	temp;
	t_move	new_move;

	best = move->nb_ra + move->nb_rb;
	temp.nb_ra = move->nb_ra;
	temp.nb_rb = move->nb_rb;
	temp.nb_rra = 0;
	temp.nb_rrb = 0;
	new_move = (t_move){move->nb_ra, 0, 0, move->nb_rrb};
	update_move(&temp, new_move, &best);
	new_move = (t_move){0, move->nb_rb, move->nb_rra, 0};
	update_move(&temp, new_move, &best);
	new_move = (t_move){0, 0, move->nb_rra, move->nb_rrb};
	update_move(&temp, new_move, &best);
	*move = temp;
}

void	calculate_move(t_stacks stacks, t_node *temp,
	t_move *temp_move, int index_a)
{
	temp_move->nb_ra = index_a;
	temp_move->nb_rra = stacks.stack_a->size - index_a;
	if (temp->value < get_max(*(stacks.stack_b))
		&& temp->value > get_min(*(stacks.stack_b)))
		temp_move->nb_rb = search_index(temp->value, stacks.stack_b);
	else
		temp_move->nb_rb = search_max_index(stacks.stack_b);
	temp_move->nb_rrb = stacks.stack_b->size - temp_move->nb_rb;
	best_move(temp_move);
}

void	select_best_move(t_stack *stack_a, t_stack *stack_b, t_move *move)
{
	int		index_a;
	t_move	temp_move;
	t_node	*temp;

	*move = (t_move){0};
	temp = stack_a->top;
	index_a = 0;
	while (index_a < stack_a->size)
	{
		calculate_move((t_stacks){stack_a, stack_b}, temp, &temp_move, index_a);
		if (index_a == 0 || (move->nb_ra + move->nb_rb + move->nb_rra
				+ move->nb_rrb > temp_move.nb_ra + temp_move.nb_rb
				+ temp_move.nb_rra + temp_move.nb_rrb))
			*move = temp_move;
		temp = temp->next;
		index_a++;
	}
}

void	sorting(t_stack *stack_a, t_stack *stack_b)
{
	t_move	move;

	if (!stack_is_sorting(stack_a))
	{
		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
		while (stack_a->size > 0)
		{
			select_best_move(stack_a, stack_b, &move);
			do_move(&move, stack_a, stack_b);
			pb(stack_a, stack_b);
		}
		while (stack_b->size > 0)
			pa(stack_a, stack_b);
	}
	while (stack_a->top->value != get_min(*stack_a))
	{
		if (search_max_index(stack_a) > stack_a->size / 2)
			rra(stack_a);
		else
			ra(stack_a);
	}
}
