/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:15:48 by vbonnard          #+#    #+#             */
/*   Updated: 2025/02/03 10:52:43 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Gestion des erreurs d’entrée.
#include "push_swap.h"

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
			ft_printf("Error\n");
			return (0);
		}
		y++;
	}
	return (1);
}

int	check_range(char *str)
{
	int	num;

	num = ft_atoi(str);
	if (num < INT_MIN || num > INT_MAX)
	{
		ft_printf("Error\n");
		return (0);
	}
	return (1);
}

int	check_duplicate(char *str, char *argv[], int index)
{
	int	i;

	i = 1;
	while (i < index)
	{
		if (ft_strcmp(argv[i], str) == 0)
		{
			ft_printf("Error\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_entry(char *argv[])
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!check_digit_and_sign(argv[i]))
			return (0);
		if (!check_range(argv[i]))
			return (0);
		if (!check_duplicate(argv[i], argv, i))
			return (0);
		i++;
	}
	return (1);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
