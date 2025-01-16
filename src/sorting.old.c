/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:15:37 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/16 13:35:31 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Implémentation des algorithmes de tri.

#include "push_swap.h"

int	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	smallest;
	int	count;

	count = 0;
	while (stack_a->size > 1)
	{
		smallest = find_smallest(stack_a);
		while (stack_a->top->value != smallest)
		{
			if (is_in_top_half(stack_a, smallest))
			{
				ra(stack_a);
				count++;
			}
			else
			{
				rra(stack_a);
				count++;
			}
		}
		pb(stack_a, stack_b);
		count++;
	}
	while (stack_b->size > 0)
	{
		pa(stack_a, stack_b);
		count++;
	}
	return (count);
}

//Trouver le plus petit élément dans la pile a
int	find_smallest(t_stack *stack_a)
{
	t_node	*current;
	int		smallest;

	current = stack_a->top;
	smallest = current->value;
	while (current)
	{
		if (current->value < smallest)
			smallest = current->value;
		current = current->next;
	}
	return (smallest);
}


//Retourne vrai si l'élément le plus petit est dans la moitié supérieure de la pile a
int	is_in_top_half(t_stack *stack_a, int smallest)
{
	int		mid;
	int		count;
	t_node	*current;

	mid = stack_a->size / 2;
	count = 0;
	current = stack_a->top;
	while (current)
	{
		if (current->value == smallest)
			break ;
		current = current->next;
		count++;
	}
	return (count <= mid);
}



