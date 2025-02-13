/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:10:46 by vbonnard          #+#    #+#             */
/*   Updated: 2025/02/13 12:10:47 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTION_H
# define INSTRUCTION_H

# include "push_swap.h"

/**
 * @brief Échange les deux premiers éléments de la pile a.
 *
 * @param a Pointeur vers la pile a.
 */
void	sa(t_stack *a);

/**
 * @brief Échange les deux premiers éléments de la pile b.
 *
 * @param b Pointeur vers la pile b.
 */
void	sb(t_stack *b);

/**
 * @brief Échange les deux premiers éléments des piles a et b.
 *
 * @param a Pointeur vers la pile a.
 * @param b Pointeur vers la pile b.
 */
void	ss(t_stack *a, t_stack *b);

/**
 * @brief Déplace le premier élément de la pile b vers le sommet de la pile a.
 *
 * @param a Pointeur vers la pile a.
 * @param b Pointeur vers la pile b.
 */
void	pa(t_stack *a, t_stack *b);

/**
 * @brief Déplace le premier élément de la pile a vers le sommet de la pile b.
 *
 * @param a Pointeur vers la pile a.
 * @param b Pointeur vers la pile b.
 */
void	pb(t_stack *a, t_stack *b);

/**

	* @brief Fait tourner la pile a vers le haut (le premier élément devient le dernier).
 *
 * @param a Pointeur vers la pile a.
 */
void	ra(t_stack *a);

/**

	* @brief Fait tourner la pile b vers le haut (le premier élément devient le dernier).
 *
 * @param b Pointeur vers la pile b.
 */
void	rb(t_stack *b);

/**
 * @brief Fait tourner vers le haut les piles a et b.
 *
 * @param a Pointeur vers la pile a.
 * @param b Pointeur vers la pile b.
 */
void	rr(t_stack *a, t_stack *b);

/**

	* @brief Fait tourner la pile a vers le bas (le dernier élément devient le premier).
 *
 * @param a Pointeur vers la pile a.
 */
void	rra(t_stack *a);

/**

	* @brief Fait tourner la pile b vers le bas (le dernier élément devient le premier).
 *
 * @param b Pointeur vers la pile b.
 */
void	rrb(t_stack *b);

/**
 * @brief Fait tourner vers le bas les piles a et b.
 *
 * @param a Pointeur vers la pile a.
 * @param b Pointeur vers la pile b.
 */
void	rrr(t_stack *a, t_stack *b);

#endif
