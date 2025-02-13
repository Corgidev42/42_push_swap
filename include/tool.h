/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:36:59 by vbonnard          #+#    #+#             */
/*   Updated: 2025/02/13 12:22:08 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOL_H
# define TOOL_H

# include "push_swap.h"

/**
 * @brief Récupère la valeur maximale dans une pile.
 *
 * @param stack Pile à analyser.
 * @return int Valeur maximale présente dans la pile.
 */
int		get_max(t_stack stack);

/**
 * @brief Récupère la valeur minimale dans une pile.
 *
 * @param stack Pile à analyser.
 * @return int Valeur minimale présente dans la pile.
 */
int		get_min(t_stack stack);

/**

	* @brief Recherche l'index de l'élément de valeur la plus proche en dessous de la valeur donnée dans la pile b.
 *
 * @param value Valeur de référence.
 * @param stack_b Pointeur vers la pile b.
 * @return int Index de l'élément le plus proche en dessous de la valeur,
	ou 0 si aucun trouvé.
 */
int		search_index(int value, t_stack *stack_b);

/**
 * @brief Recherche l'index de la valeur maximale dans la pile.
 *
 * @param stack Pointeur vers la pile.
 * @return int Index de l'élément contenant la valeur maximale.
 */
int		search_max_index(t_stack *stack);

/**

	* @brief Vérifie si la pile est triée dans l'ordre croissant en considérant la rotation possible.
 *
 * @param stack Pointeur vers la pile.
 * @return int Retourne 1 si la pile est triée, sinon 0.
 */
int		stack_is_sorting(t_stack *stack);

/**

	* @brief Applique les rotations simultanées ou individuelles sur les piles a et b en fonction des valeurs dans la structure t_move.
 *
 * @param move Pointeur vers la structure contenant les opérations à effectuer.
 * @param stack_a Pointeur vers la pile a.
 * @param stack_b Pointeur vers la pile b.
 */
void	apply_rotation(t_move *move, t_stack *stack_a, t_stack *stack_b);

/**

	* @brief Applique les rotations inverses simultanées ou individuelles sur les piles a et b en fonction des valeurs dans la structure t_move.
 *
 * @param move Pointeur vers la structure contenant les opérations à effectuer.
 * @param stack_a Pointeur vers la pile a.
 * @param stack_b Pointeur vers la pile b.
 */
void	apply_reverse_rotation(t_move *move, t_stack *stack_a,
			t_stack *stack_b);

/**

	* @brief Exécute les mouvements de rotation ou rotation inverse sur les piles a et b selon la structure t_move.
 *
 * @param move Pointeur vers la structure contenant les opérations à effectuer.
 * @param stack_a Pointeur vers la pile a.
 * @param stack_b Pointeur vers la pile b.
 */
void	do_move(t_move *move, t_stack *stack_a, t_stack *stack_b);
#endif
