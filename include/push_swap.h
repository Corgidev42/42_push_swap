/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:16:06 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/08 09:11:07 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>

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
void				print_stacks(const char *message, t_stack *stack_a,
						t_stack *stack_b);
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
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);

// error_handling.c
int					check_digit_and_sign(char *str);
int					check_range(char *str);
int					check_entry(char *argv[]);

// sorting.c
int					sort_stack(t_stack *stack_a, t_stack *stack_b);
int					find_smallest(t_stack *stack_a);
int					is_in_top_half(t_stack *stack_a, int smallest);

#endif
