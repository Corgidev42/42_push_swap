/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:12:19 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/16 15:36:29 by vbonnard         ###   ########.fr       */
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
	ft_printf("rra\n");
}

void	rrb(t_stack *b)
{
	t_node	*temp;
	t_node	*second_last;

	if (b->size > 1)
	{
		second_last = b->top;
		while (second_last->next && second_last->next->next)
			second_last = second_last->next;
		temp = second_last->next;
		second_last->next = NULL;
		temp->next = b->top;
		b->top = temp;
	}
	ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
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
	if (b->size > 1)
	{
		second_last = b->top;
		while (second_last->next && second_last->next->next)
			second_last = second_last->next;
		temp = second_last->next;
		second_last->next = NULL;
		temp->next = b->top;
		b->top = temp;
	}
	ft_printf("rrr\n");
}
