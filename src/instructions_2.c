/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:12:08 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/16 15:36:36 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_printf("ra\n");
}

void	rb(t_stack *b)
{
	t_node	*temp;
	t_node	*last;

	if (b->size > 1)
	{
		temp = b->top;
		last = b->top;
		while (last->next)
			last = last->next;
		b->top = b->top->next;
		last->next = temp;
		temp->next = NULL;
	}
	ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
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
	if (b->size > 1)
	{
		temp = b->top;
		last = b->top;
		while (last->next)
			last = last->next;
		b->top = b->top->next;
		last->next = temp;
		temp->next = NULL;
	}
	ft_printf("rr\n");
}
