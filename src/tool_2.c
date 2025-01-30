/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:38:38 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/30 10:39:11 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_rotation(t_move *move, t_stack *stack_a, t_stack *stack_b)
{
	while (move->nb_ra > 0 && move->nb_rb > 0 && move->nb_ra-- && move->nb_rb--)
		rr(stack_a, stack_b);
	while (move->nb_ra-- > 0)
		ra(stack_a);
	while (move->nb_rb-- > 0)
		rb(stack_b);
}

void	apply_reverse_rotation(t_move *move, t_stack *stack_a, t_stack *stack_b)
{
	while (move->nb_rra > 0 && move->nb_rrb > 0 && move->nb_rra--
		&& move->nb_rrb--)
		rrr(stack_a, stack_b);
	while (move->nb_rra-- > 0)
		rra(stack_a);
	while (move->nb_rrb-- > 0)
		rrb(stack_b);
}

void	do_move(t_move *move, t_stack *stack_a, t_stack *stack_b)
{
	apply_rotation(move, stack_a, stack_b);
	apply_reverse_rotation(move, stack_a, stack_b);
}
