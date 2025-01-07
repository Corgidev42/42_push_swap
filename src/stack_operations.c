/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:15:11 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/07 15:30:53 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

// Fonctions pour gérer les piles (ajout/suppression, affichage).

// Fonction pour créer une pile vide
t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

// Ajouter un élément (push)
void	push(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	new_node->value = value;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
}

// Retirer un élément (pop)
int	pop(t_stack *stack)
{
	t_node	*temp;
	int		value;

	if (stack->top == NULL)
	{
		ft_printf("Stack is empty!\n");
		return (-1); // ou autre valeur pour signaler une erreur
	}
	temp = stack->top;
	value = temp->value;
	stack->top = temp->next;
	free(temp);
	stack->size--;
	return (value);
}

// Afficher les 2 piles
void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current_a;
	t_node	*current_b;

	current_a = stack_a->top;
	current_b = stack_b->top;
	ft_printf("[A]   [B]\n");
	while (current_a || current_b)
	{
		if (current_a)
		{
			ft_printf("%d    ", current_a->value); // Affiche la valeur de 'A'
			current_a = current_a->next;
		}
		else
			ft_printf("     "); // Espace si la pile A est vide
		if (current_b)
		{
			ft_printf("%d", current_b->value); // Affiche la valeur de 'B'
			current_b = current_b->next;
		}
		ft_printf("\n");
	}
	ft_printf("\n");
}

// Vérifier si une pile est vide
int	is_empty(t_stack *stack)
{
	return (stack->size == 0);
}
