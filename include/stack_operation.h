/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:11:14 by vbonnard          #+#    #+#             */
/*   Updated: 2025/02/13 12:11:15 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_OPERATION_H
# define STACK_OPERATION_H

# include "push_swap.h"

/**
 * @brief Crée une nouvelle pile vide.
 *
 * @return t_stack* Pointeur vers la pile nouvellement créée.
 */
t_stack	*create_stack(void);

/**
 * @brief Empile une nouvelle valeur au sommet de la pile.
 *
 * @param stack Pointeur vers la pile.
 * @param value Valeur entière à ajouter.
 */
void	push(t_stack *stack, int value);

/**
 * @brief Dépile l'élément au sommet de la pile et renvoie sa valeur.
 *
 * @param stack Pointeur vers la pile.
 * @return int Valeur de l'élément dépilé, ou -1 si la pile est vide.
 */
int		pop(t_stack *stack);

/**
 * @brief Affiche l'état actuel des piles a et b avec un message.
 *
 * @param message Message à afficher avant l'état des piles.
 * @param stack_a Pointeur vers la pile a.
 * @param stack_b Pointeur vers la pile b.
 */
void	print_stacks(const char *message, t_stack *stack_a, t_stack *stack_b);

/**
 * @brief Vérifie si la pile est vide.
 *
 * @param stack Pointeur vers la pile.
 * @return int Retourne 1 si la pile est vide, 0 sinon.
 */
int		is_empty(t_stack *stack);

#endif
