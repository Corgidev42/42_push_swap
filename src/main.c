/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:14:47 by vbonnard          #+#    #+#             */
/*   Updated: 2025/02/03 13:52:39 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
