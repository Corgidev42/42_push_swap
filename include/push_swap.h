/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:16:06 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/07 15:52:25 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

// stack_operations.c
t_stack				*create_stack(void);
void				push(t_stack *stack, int value);
int					pop(t_stack *stack);
void				print_stacks(t_stack *stack_a, t_stack *stack_b);
int					is_empty(t_stack *stack);

// instructions.c
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);

void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);

void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);

void				rra(t_stack *a);
// Fait une rotation inversée sur la pile 'a'
void				rrb(t_stack *b);
// Fait une rotation inversée sur la pile 'b'
void				rrr(t_stack *a, t_stack *b);
// Fait une rotation inversée sur les deux piles
#endif
