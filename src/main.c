/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:14:47 by vbonnard          #+#    #+#             */
/*   Updated: 2025/02/03 10:55:29 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**numbers;
	int		i;

	stack_a = create_stack();
	stack_b = create_stack();
	if (argc > 1)
	{
		if (argc == 2)
			numbers = ft_split(argv[1], ' ');
		else
			numbers = &argv[1];
		if (check_entry(numbers) == 1)
		{
			i = 0;
			while (numbers[i])
			{
				push(stack_a, ft_atoi(numbers[i]));
				i++;
			}
			solve(stack_a, stack_b);
		}
		if (argc == 2)
			free_split(numbers);
	}
	free(stack_a);
	free(stack_b);
}
