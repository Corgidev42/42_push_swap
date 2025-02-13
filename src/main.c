/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:14:47 by vbonnard          #+#    #+#             */
/*   Updated: 2025/02/13 12:20:54 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Gère l'entrée utilisateur et initialise les piles.
 *
 * Cette fonction traite les arguments passés au programme,
	vérifie leur validité,
 * et initialise les piles stack_a et stack_b en fonction des valeurs fournies.
 *
 * @param argc Le nombre d'arguments passés au programme.
 * @param argv Un tableau de chaînes de caractères représentant les arguments.
 * @param stack_a Un pointeur vers la pile A à initialiser.
 * @param stack_b Un pointeur vers la pile B à initialiser.
 *
 * Si un seul argument est passé (argc == 2), il est supposé contenir une liste

	* de nombres séparés par des espaces. Ces nombres sont alors extraits et traités.
 * Si plusieurs arguments sont passés (argc > 2),
	chaque argument est traité comme
 * un nombre individuel.
 *
 * La fonction vérifie ensuite la validité des nombres extraits en appelant
 * check_entry(). Si les nombres sont valides, ils sont poussés dans stack_a.
 * Enfin, la fonction solve() est appelée pour résoudre le problème de tri.
 *
 * Si un seul argument a été passé, la mémoire allouée pour les nombres extraits
 * est libérée avant la fin de la fonction.
 */
void	handle_input(int argc, char *argv[], t_stack *stack_a, t_stack *stack_b)
{
	char	**numbers;
	int		i;

	if (argc == 2)
	{
		numbers = ft_split(argv[1], ' ');
		i = 0;
		while (numbers[i])
			i++;
		i--;
	}
	else
	{
		numbers = &argv[1];
		i = argc - 2;
	}
	if (check_entry(numbers) == 1)
	{
		while (i >= 0)
			push(stack_a, ft_atoi(numbers[i--]));
		solve(stack_a, stack_b);
	}
	if (argc == 2)
		free_split(numbers);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = create_stack();
	stack_b = create_stack();
	if (argc > 1)
		handle_input(argc, argv, stack_a, stack_b);
	while (stack_a->size)
		pop(stack_a);
	free(stack_a);
	free(stack_b);
	return (0);
}
