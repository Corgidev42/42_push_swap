/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:36:16 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/16 16:41:21 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_stack stack)
{
	t_node	*temp;
	int		max;

	max = stack.top->value;
	temp = stack.top;
	while (temp)
	{
		if (temp->value > max)
			max = temp->value;
		temp = temp->next;
	}
	return (max);
}

int	get_min(t_stack stack)
{
	t_node	*temp;
	int		min;

	min = stack.top->value;
	temp = stack.top;
	while (temp)
	{
		if (temp->value < min)
			min = temp->value;
		temp = temp->next;
	}
	return (min);
}

int	search_index(int value, t_stack *stack_b)
{
	int		i;
	t_node	*temp;
	int		close_value;
	int		close_index;

	i = 0;
	close_value = INT_MIN;
	close_index = 0;
	temp = stack_b->top;
	while (temp)
	{
		if (temp->value < value && temp->value > close_value)
		{
			close_value = temp->value;
			close_index = i;
		}
		i++;
		temp = temp->next;
	}
	return (close_index);
}

int	search_max_index(t_stack *stack)
{
	int		i;
	t_node	*temp;
	int		max;
	int		max_index;

	i = 0;
	max_index = 0;
	max = stack->top->value;
	temp = stack->top;
	while (temp)
	{
		if (temp->value > max)
		{
			max = temp->value;
			max_index = i;
		}
		i++;
		temp = temp->next;
	}
	return (max_index);
}

void	do_move(t_move *move, t_stack *stack_a, t_stack *stack_b)
{
	while (move->nb_ra > 0 && move->nb_rb > 0)
	{
		rr(stack_a, stack_b);
		move->nb_ra--;
		move->nb_rb--;
	}
	while (move->nb_ra > 0)
	{
		ra(stack_a);
		move->nb_ra--;
	}
	while (move->nb_rb > 0)
	{
		rb(stack_b);
		move->nb_rb--;
	}
	while (move->nb_rra > 0 && move->nb_rrb > 0)
	{
		rrr(stack_a, stack_b);
		move->nb_rra--;
		move->nb_rrb--;
	}
	while (move->nb_rra > 0)
	{
		rra(stack_a);
		move->nb_rra--;
	}
	while (move->nb_rrb > 0)
	{
		rrb(stack_b);
		move->nb_rrb--;
	}
}

void	best_move(t_move *move)
{
	int		best;
	t_move	temp;

	temp.nb_ra = move->nb_ra;
	temp.nb_rb = move->nb_rb;
	temp.nb_rra = 0;
	temp.nb_rrb = 0;
	best = move->nb_ra + move->nb_rb;
	if (move->nb_ra + move->nb_rrb < best)
	{
		temp.nb_ra = move->nb_ra;
		temp.nb_rb = 0;
		temp.nb_rra = 0;
		temp.nb_rrb = move->nb_rrb;
		best = move->nb_ra + move->nb_rrb;
	}
	if (move->nb_rra + move->nb_rb < best)
	{
		temp.nb_ra = 0;
		temp.nb_rb = move->nb_rb;
		temp.nb_rra = move->nb_rra;
		temp.nb_rrb = 0;
		best = move->nb_rra + move->nb_rb;
	}
	if (move->nb_rra + move->nb_rrb < best)
	{
		temp.nb_ra = 0;
		temp.nb_rb = 0;
		temp.nb_rra = move->nb_rra;
		temp.nb_rrb = move->nb_rrb;
	}
	move->nb_ra = temp.nb_ra;
	move->nb_rb = temp.nb_rb;
	move->nb_rra = temp.nb_rra;
	move->nb_rrb = temp.nb_rrb;
}

void	sorting(t_stack *stack_a, t_stack *stack_b)
{
	t_move	move;
	int		current_best_rot;
	int		index_a;
	int		i;
	t_node	*temp;
	t_move	temp_move;

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	while (stack_a->size > 0)
	{
		temp = stack_a->top;
		i = 0;
		index_a = 0;
		while (i < stack_a->size)
		{
			temp_move.nb_ra = index_a;
			temp_move.nb_rra = stack_a->size - index_a;
			if (temp->value < get_max(*stack_b)
				&& temp->value > get_min(*stack_b))
			{
				current_best_rot = search_index(temp->value, stack_b);
				temp_move.nb_rb = current_best_rot;
				temp_move.nb_rrb = stack_b->size - current_best_rot;
			}
			else
			{
				current_best_rot = search_max_index(stack_b);
				temp_move.nb_rb = current_best_rot;
				temp_move.nb_rrb = stack_b->size - current_best_rot;
			}
			best_move(&temp_move);
			if (i == 0 || move.nb_ra + move.nb_rb + move.nb_rra
				+ move.nb_rrb > temp_move.nb_ra + temp_move.nb_rb
				+ temp_move.nb_rra + temp_move.nb_rrb)
			{
				move.nb_ra = temp_move.nb_ra;
				move.nb_rb = temp_move.nb_rb;
				move.nb_rra = temp_move.nb_rra;
				move.nb_rrb = temp_move.nb_rrb;
			}
			temp = temp->next;
			i++;
			index_a++;
		}
		do_move(&move, stack_a, stack_b);
		pb(stack_a, stack_b);
	}
	while (stack_b->size > 0)
		pa(stack_a, stack_b);
	if (search_max_index(stack_a) > stack_a->size / 2)
		while (stack_a->top->value != get_min(*stack_a))
			rra(stack_a);
	else
		while (stack_a->top->value != get_min(*stack_a))
			ra(stack_a);
}
