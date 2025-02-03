/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:15:11 by vbonnard          #+#    #+#             */
/*   Updated: 2025/02/03 13:44:18 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

// Fonctions pour gérer les piles (ajout/suppression, affichage).

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

void	push(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	new_node->value = value;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
}

int	pop(t_stack *stack)
{
	t_node	*temp;
	int		value;

	if (stack->top == NULL)
	{
		ft_printf("Stack is empty!\n");
		return (-1);
	}
	temp = stack->top;
	value = temp->value;
	stack->top = temp->next;
	free(temp);
	stack->size--;
	return (value);
}

void	print_stacks(const char *message, t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current_a;
	t_node	*current_b;

	ft_printf("%s\n", message);
	current_a = stack_a->top;
	current_b = stack_b->top;
	while (current_a || current_b)
	{
		if (current_a)
		{
			ft_printf("%d    ", current_a->value);
			current_a = current_a->next;
		}
		else
			ft_printf("     ");
		if (current_b)
		{
			ft_printf("%d", current_b->value);
			current_b = current_b->next;
		}
		ft_printf("\n");
	}
	ft_printf("_ _\n");
	ft_printf("a b\n\n");
}

int	is_empty(t_stack *stack)
{
	return (stack == NULL || stack->top == NULL);
}
