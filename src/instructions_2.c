/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:12:08 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/07 15:51:27 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Fait une rotation sur la pile 'a'
void	ra(t_stack *a)
{
	t_node	*temp;
	t_node	*last;

	if (a->size > 1)
	{
		temp = a->top;
		last = a->top;
		while (last->next)
			last = last->next;
		a->top = a->top->next;
		last->next = temp;
		temp->next = NULL;
	}
}

// Fait une rotation sur la pile 'b'
void	rb(t_stack *b)
{
	ra(b);
}

// Fait une rotation sur les deux piles
void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}
