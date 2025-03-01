/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:36:59 by vbonnard          #+#    #+#             */
/*   Updated: 2025/02/03 14:43:14 by vbonnard         ###   ########.fr       */
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

int	stack_is_sorting(t_stack *stack)
{
	int		min;
	int		i;
	t_node	*current;
	t_node	*next;

	min = get_min(*stack);
	current = stack->top;
	while (current->value != min)
		current = current->next;
	i = 0;
	while (i < stack->size - 1)
	{
		next = current->next;
		if (!next)
			next = stack->top;
		if (current->value > next->value)
			return (0);
		current = next;
		i++;
	}
	return (1);
}
