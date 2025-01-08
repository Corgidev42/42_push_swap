/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:14:47 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/08 09:12:20 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	i = 1;
	stack_a = create_stack();
	stack_b = create_stack();
	if (argc > 1)
	{
		if (check_entry(argv) == 1)
		{
			while (argv[i])
			{
				push(stack_b, ft_atoi(argv[i]));
				i++;
			}
			i = 0;
			while (i < argc)
			{
				pa(stack_a, stack_b);
				i++;
			}
			print_stacks("test", stack_a, stack_b);
			ft_printf("Nombre d'operation : %d\n" ,sort_stack(stack_a, stack_b));
			print_stacks("sorted", stack_a, stack_b);
		}
	}
	free(stack_a);
	free(stack_b);
}
