/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:15:48 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/07 19:01:56 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Gestion des erreurs d’entrée.
#include "push_swap.h"
#include <stdlib.h>

// Fonction pour vérifier les chiffres et les signes
int	check_digit_and_sign(char *str)
{
	int	y;

	y = 0;
	if (str[y] == '-' || str[y] == '+')
		y++;
	while (str[y])
	{
		if (!ft_isdigit(str[y]))
		{
			ft_printf("Invalid character detected in: %s\n", str);
			return (0);
		}
		y++;
	}
	return (1);
}

// Fonction pour vérifier que la valeur est dans la plage valide
int	check_range(char *str)
{
	int	num;

	num = ft_atoi(str);
	if (num < INT_MIN || num > INT_MAX)
	{
		ft_printf("Value out of range: %s\n", str);
		return (0);
	}
	return (1);
}

// Fonction pour vérifier si un nombre est déjà dans la liste
int	check_duplicate(char *str, char *argv[], int index)
{
	int	i;

	i = 1;
	while (i < index)
	{
		if (ft_strcmp(argv[i], str) == 0)
			return (0);
		i++;
	}
	return (1);
}

// Fonction principale pour vérifier les entrées
int	check_entry(char *argv[])
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!check_digit_and_sign(argv[i]))
			return (0);
		if (!check_range(argv[i]))
			return (0);
		if (!check_duplicate(argv[i], argv, i))
		{
			ft_printf("Duplicate value found: %s\n", argv[i]);
			return (0);
		}
		i++;
	}
	return (1);
}
