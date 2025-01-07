/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:12:19 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/07 16:04:30 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a)
{
	t_node	*temp;
	t_node	*second_last;

	if (a->size > 1)
	{
		second_last = a->top;
		while (second_last->next && second_last->next->next)
			second_last = second_last->next;
		temp = second_last->next;
		second_last->next = NULL;
		temp->next = a->top;
		a->top = temp;
	}
}

// Fait une rotation inversée sur la pile 'b'
void	rrb(t_stack *b)
{
	rra(b);
}

// Fait une rotation inversée sur les deux piles
void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}
