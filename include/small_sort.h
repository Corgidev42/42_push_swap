/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:20:00 by vbonnard          #+#    #+#             */
/*   Updated: 2025/02/13 12:20:11 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SMALL_SORT_H
# define SMALL_SORT_H

# include "push_swap.h"

/**

	* @brief Choisit et applique la stratégie de tri appropriée en fonction de la taille de la pile a.
 *
 * @param stack_a Pointeur vers la pile a.
 * @param stack_b Pointeur vers la pile b.
 */
void	solve(t_stack *stack_a, t_stack *stack_b);

/**
 * @brief Trie une pile de 3 éléments.
 *
 * @param stack_a Pointeur vers la pile a.
 */
void	ps_sort_3(t_stack *stack_a);

/**

	* @brief Trie une pile de 4 éléments en utilisant la pile b comme pile auxiliaire.
 *
 * @param stack_a Pointeur vers la pile a.
 * @param stack_b Pointeur vers la pile b.
 */
void	ps_sort_4(t_stack *stack_a, t_stack *stack_b);

/**
 * @brief Retourne la deuxième plus petite valeur d'une pile.
 *
 * @param stack Pile à analyser.
 * @return int Deuxième plus petite valeur trouvée.
 */
int		get_second_min(t_stack stack);

/**

	* @brief Trie une pile de 5 éléments en utilisant la pile b comme pile auxiliaire.
 *
 * @param stack_a Pointeur vers la pile a.
 * @param stack_b Pointeur vers la pile b.
 */
void	ps_sort_5(t_stack *stack_a, t_stack *stack_b);

#endif
