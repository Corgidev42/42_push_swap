/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:14:47 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/30 10:55:59 by vbonnard         ###   ########.fr       */
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
			while (argc - i >= 1)
			{
				push(stack_a, ft_atoi(argv[argc - i]));
				i++;
			}
			solve(stack_a, stack_b);
		}
	}
	free(stack_a);
	free(stack_b);
}
