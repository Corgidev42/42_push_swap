/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:36:16 by vbonnard          #+#    #+#             */
/*   Updated: 2025/02/13 12:21:57 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H

# include "push_swap.h"

/**
 * @brief Met à jour le meilleur coup à jouer en comparant les coûts.
 *
 * @param temp Pointeur vers le meilleur coup temporaire.
 * @param move Coup en cours de vérification.
 * @param best Pointeur vers le coût du meilleur coup actuel.
 */
void	update_move(t_move *temp, t_move move, int *best);

/**

	* @brief Détermine la meilleure combinaison de rotations pour effectuer le mouvement.
 *
 * @param move Pointeur vers la structure contenant les opérations à optimiser.
 */
void	best_move(t_move *move);

/**

	* @brief Calcule le coût des mouvements nécessaires pour placer un élément de la pile a dans la pile b.
 *
 * @param stacks Structure contenant les deux piles.
 * @param temp Élément de la pile a en cours d’évaluation.

	* @param temp_move Pointeur vers la structure contenant les mouvements calculés.
 * @param index_a Index de l'élément dans la pile a.
 */
void	calculate_move(t_stacks stacks, t_node *temp, t_move *temp_move,
			int index_a);

/**

	* @brief Sélectionne le meilleur mouvement pour déplacer un élément de la pile a vers la pile b.
 *
 * @param stack_a Pointeur vers la pile a.
 * @param stack_b Pointeur vers la pile b.

	* @param move Pointeur vers la structure contenant le meilleur mouvement trouvé.
 */
void	select_best_move(t_stack *stack_a, t_stack *stack_b, t_move *move);

/**
 * @brief Trie la pile a en utilisant la pile b comme pile auxiliaire.
 *
 * @param stack_a Pointeur vers la pile a.
 * @param stack_b Pointeur vers la pile b.
 */
void	sorting(t_stack *stack_a, t_stack *stack_b);

#endif
