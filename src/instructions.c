/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:14:54 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/07 15:31:35 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Implémentation des instructions (sa, sb, etc.).

#include "push_swap.h"

// Swap les deux premiers éléments de la pile 'a'
void	sa(t_stack *a)
{
	int	temp;

	temp = a->top->value;
	if (a->size > 1)
	{
		a->top->value = a->top->next->value;
		a->top->next->value = temp;
	}
}

// Swap les deux premiers éléments de la pile 'b'
void	sb(t_stack *b)
{
	sa(b);
}

// Swap les deux premiers éléments des deux piles
void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

// Push le premier élément de 'b' vers 'a'
void	pa(t_stack *a, t_stack *b)
{
	if (is_empty(b))
		return ;
	push(a, b->top->value);
	pop(b);
}

// Push le premier élément de 'a' vers 'b'
void	pb(t_stack *a, t_stack *b)
{
	if (is_empty(a))
		return ;
	push(b, a->top->value);
	pop(a);
}
