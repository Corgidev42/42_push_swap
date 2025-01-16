/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:14:54 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/16 16:31:48 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Implémentation des instructions (sa, sb, etc.).

#include "push_swap.h"

void	sa(t_stack *a)
{
	int	temp;

	temp = a->top->value;
	if (a->size > 1)
	{
		a->top->value = a->top->next->value;
		a->top->next->value = temp;
	}
	ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	int	temp;

	temp = b->top->value;
	if (b->size > 1)
	{
		b->top->value = b->top->next->value;
		b->top->next->value = temp;
	}
	ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	int	temp;

	temp = a->top->value;
	if (a->size > 1)
	{
		a->top->value = a->top->next->value;
		a->top->next->value = temp;
	}
	temp = b->top->value;
	if (b->size > 1)
	{
		b->top->value = b->top->next->value;
		b->top->next->value = temp;
	}
	ft_printf("ss\n");
}

void	pa(t_stack *a, t_stack *b)
{
	if (is_empty(b))
		return ;
	push(a, b->top->value);
	pop(b);
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	if (is_empty(a))
		return ;
	push(b, a->top->value);
	pop(a);
	ft_printf("pb\n");
}
