/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:46:06 by vbonnard          #+#    #+#             */
/*   Updated: 2025/02/13 12:19:42 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 5)
	{
		if (stack_a->size == 1)
			return ;
		if (stack_a->size == 2
			&& stack_a->top->value > stack_a->top->next->value)
			sa(stack_a);
		else if (stack_a->size == 3)
			ps_sort_3(stack_a);
		else if (stack_a->size == 4)
			ps_sort_4(stack_a, stack_b);
		else if (stack_a->size == 5)
			ps_sort_5(stack_a, stack_b);
		return ;
	}
	sorting(stack_a, stack_b);
}

void	ps_sort_3(t_stack *stack_a)
{
	if (stack_a->top->value < stack_a->top->next->value
		&& stack_a->top->next->next->value > stack_a->top->value
		&& stack_a->top->next->value > stack_a->top->next->next->value)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (stack_a->top->value > stack_a->top->next->value
		&& stack_a->top->next->next->value < stack_a->top->value
		&& stack_a->top->next->value > stack_a->top->next->next->value)
	{
		ra(stack_a);
		sa(stack_a);
	}
	else if (stack_a->top->value < stack_a->top->next->value
		&& stack_a->top->next->next->value < stack_a->top->next->value)
		rra(stack_a);
	else if (stack_a->top->value > stack_a->top->next->next->value
		&& stack_a->top->value > stack_a->top->next->value)
		ra(stack_a);
	else if (stack_a->top->value > stack_a->top->next->value
		&& stack_a->top->value < stack_a->top->next->next->value)
		sa(stack_a);
}

void	ps_sort_4(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	while (i != 1)
	{
		if (stack_a->top->value == get_min(*stack_a))
		{
			pb(stack_a, stack_b);
			i++;
		}
		else
			ra(stack_a);
	}
	ps_sort_3(stack_a);
	pa(stack_a, stack_b);
}

int	get_second_min(t_stack stack)
{
	int		min;
	int		second_min;
	t_node	*current;

	min = get_min(stack);
	second_min = INT_MAX;
	current = stack.top;
	while (current)
	{
		if (current->value > min && current->value < second_min)
			second_min = current->value;
		current = current->next;
	}
	return (second_min);
}

void	ps_sort_5(t_stack *stack_a, t_stack *stack_b)
{
	int	min;
	int	second_min;

	min = get_min(*stack_a);
	second_min = get_second_min(*stack_a);
	while (stack_a->top->value != min && stack_a->top->value != second_min)
		ra(stack_a);
	pb(stack_a, stack_b);
	while (stack_a->top->value != min && stack_a->top->value != second_min)
		ra(stack_a);
	pb(stack_a, stack_b);
	ps_sort_3(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	if (stack_a->top->value > stack_a->top->next->value)
		sa(stack_a);
}
