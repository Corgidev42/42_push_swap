/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:14:47 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/07 18:34:07 by vbonnard         ###   ########.fr       */
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
				push(stack_a, ft_atoi(argv[i]));
				i++;
			}
			print_stacks("test", stack_a, stack_b);
		}
	}
	else
	{
		ft_printf("./push_swap [value1] [value2] [value3]...\n");
		ft_printf("ex : ./push_swap 2 1 3 6 5 8\n");
	}
	free(stack_a);
	free(stack_b);
}
