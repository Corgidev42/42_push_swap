/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:36:16 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/30 10:40:18 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_move(t_move *temp, int ra, int rb, int rra, int rrb, int *best)
{
	int	cost;

	cost = ra + rb + rra + rrb;
	if (cost < *best)
	{
		temp->nb_ra = ra;
		temp->nb_rb = rb;
		temp->nb_rra = rra;
		temp->nb_rrb = rrb;
		*best = cost;
	}
}

void	best_move(t_move *move)
{
	int		best;
	t_move	temp;

	best = move->nb_ra + move->nb_rb;
	temp.nb_ra = move->nb_ra;
	temp.nb_rb = move->nb_rb;
	temp.nb_rra = 0;
	temp.nb_rrb = 0;
	update_move(&temp, move->nb_ra, 0, 0, move->nb_rrb, &best);
	update_move(&temp, 0, move->nb_rb, move->nb_rra, 0, &best);
	update_move(&temp, 0, 0, move->nb_rra, move->nb_rrb, &best);
	*move = temp;
}

void	calculate_move(t_stack *stack_a, t_node *temp, t_stack *stack_b,
		t_move *temp_move, int index_a)
{
	temp_move->nb_ra = index_a;
	temp_move->nb_rra = stack_a->size - index_a;
	if (temp->value < get_max(*stack_b) && temp->value > get_min(*stack_b))
		temp_move->nb_rb = search_index(temp->value, stack_b);
	else
		temp_move->nb_rb = search_max_index(stack_b);
	temp_move->nb_rrb = stack_b->size - temp_move->nb_rb;
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
		calculate_move(stack_a, temp, stack_b, &temp_move, index_a);
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
	while (stack_a->top->value != get_min(*stack_a))
	{
		if (search_max_index(stack_a) > stack_a->size / 2)
			rra(stack_a);
		else
			ra(stack_a);
	}
}
