/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:10:35 by vbonnard          #+#    #+#             */
/*   Updated: 2025/02/13 12:10:36 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLING_H
# define ERROR_HANDLING_H

# include "push_swap.h"

/**
 * @brief Vérifie si la chaîne est composée uniquement de chiffres et de signes.
 *
 * @param str Chaîne à vérifier.
 * @return int Retourne 1 si valide, sinon 0.
 */
int		check_digit_and_sign(char *str);

/**
 * @brief Vérifie si la valeur est comprise dans la plage des entiers (INT_MIN,
	INT_MAX).
 *
 * @param str Chaîne représentant un nombre.
 * @return int Retourne 1 si valide, sinon 0.
 */
int		check_range(char *str);

/**
 * @brief Vérifie si la valeur est dupliquée dans les arguments.
 *
 * @param str Chaîne représentant un nombre.
 * @param argv Tableau de chaînes (arguments).
 * @param index Index de l'élément à vérifier.
 * @return int Retourne 1 si aucune duplication, sinon 0.
 */
int		check_duplicate(char *str, char *argv[], int index);

/**
 * @brief Vérifie l'ensemble des entrées pour valider chiffres,
	plage et doublons.
 *
 * @param argv Tableau de chaînes (arguments).
 * @return int Retourne 1 si toutes les entrées sont valides, sinon 0.
 */
int		check_entry(char *argv[]);

/**
 * @brief Libère la mémoire allouée pour un tableau de chaînes.
 *
 * @param split Tableau de chaînes à libérer.
 */
void	free_split(char **split);

#endif
