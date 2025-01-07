/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:14:47 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/07 16:05:04 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Main pour tester
int	main(void)
{
	t_stack	*stack_a;
	t_stack *stack_b;

	stack_a = create_stack();
	stack_b = create_stack();

	push(stack_a, 4);
	push(stack_a, 7);
	push(stack_a, 9);
	push(stack_a, 1);
	push(stack_a, 5);
	push(stack_a, 6);
	push(stack_a, 0);
	push(stack_a, 3);
	push(stack_a, 8);
	push(stack_a, 2);

	print_stacks(stack_a, stack_b);


	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	print_stacks(stack_a, stack_b);

	ft_printf("RX\n");
	ra(stack_a);
	print_stacks(stack_a, stack_b);

	rb(stack_b);
	print_stacks(stack_a, stack_b);

	rr(stack_a, stack_b);
	print_stacks(stack_a, stack_b);

	ft_printf("RRX\n");
	rra(stack_a);
	print_stacks(stack_a, stack_b);

	rrb(stack_b);
	print_stacks(stack_a, stack_b);

	rrr(stack_a, stack_b);
	print_stacks(stack_a, stack_b);

	free(stack_a);
	free(stack_b);
	return (0);
}
