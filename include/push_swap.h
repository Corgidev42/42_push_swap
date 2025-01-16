/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:16:06 by vbonnard          #+#    #+#             */
/*   Updated: 2025/01/16 17:07:15 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "limits.h"

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

typedef struct s_move
{
	int				nb_ra;
	int				nb_rb;
	int				nb_rra;
	int				nb_rrb;
}					t_move;

// stack_operations.c
/**
 * @brief Creates a new stack.
 *
 * @return A pointer to the newly created stack.
 */
t_stack				*create_stack(void);

/**
 * @brief Pushes a value onto the stack.
 *
 * @param stack The stack to push the value onto.
 * @param value The value to push onto the stack.
 */
void				push(t_stack *stack, int value);

/**
 * @brief Pops a value from the stack.
 *
 * @param stack The stack to pop the value from.
 * @return The value popped from the stack.
 */
int					pop(t_stack *stack);

/**
 * @brief Prints the contents of two stacks with a message.
 *
 * @param message The message to print before the stacks.
 * @param stack_a The first stack to print.
 * @param stack_b The second stack to print.
 */
void				print_stacks(const char *message, t_stack *stack_a,
						t_stack *stack_b);

/**
 * @brief Checks if the stack is empty.
 *
 * @param stack The stack to check.
 * @return 1 if the stack is empty, 0 otherwise.
 */
int					is_empty(t_stack *stack);

// instructions.c
/**
 * @brief Swap the first two elements of stack a.
 *
 * @param a Pointer to stack a.
 */
void				sa(t_stack *a);

/**
 * @brief Swap the first two elements of stack b.
 *
 * @param b Pointer to stack b.
 */
void				sb(t_stack *b);

/**
 * @brief Swap the first two elements of both stacks a and b.
 *
 * @param a Pointer to stack a.
 * @param b Pointer to stack b.
 */
void				ss(t_stack *a, t_stack *b);

/**
 * @brief Push the top element of stack b onto stack a.
 *
 * @param a Pointer to stack a.
 * @param b Pointer to stack b.
 */
void				pa(t_stack *a, t_stack *b);

/**
 * @brief Push the top element of stack a onto stack b.
 *
 * @param a Pointer to stack a.
 * @param b Pointer to stack b.
 */
void				pb(t_stack *a, t_stack *b);

/**
 * @brief Rotate stack a upwards (first element becomes the last).
 *
 * @param a Pointer to stack a.
 */
void				ra(t_stack *a);

/**
 * @brief Rotate stack b upwards (first element becomes the last).
 *
 * @param b Pointer to stack b.
 */
void				rb(t_stack *b);

/**
 * @brief Rotate both stacks a and b upwards.
 *
 * @param a Pointer to stack a.
 * @param b Pointer to stack b.
 */
void				rr(t_stack *a, t_stack *b);

/**
 * @brief Reverse rotate stack a (last element becomes the first).
 *
 * @param a Pointer to stack a.
 */
void				rra(t_stack *a);

/**
 * @brief Reverse rotate stack b (last element becomes the first).
 *
 * @param b Pointer to stack b.
 */
void				rrb(t_stack *b);

/**
 * @brief Reverse rotate both stacks a and b.
 *
 * @param a Pointer to stack a.
 * @param b Pointer to stack b.
 */
void				rrr(t_stack *a, t_stack *b);

// error_handling.c
/**
 * @brief Checks if the given string contains only digits and an optional sign.
 *
 * @param str The string to check.
 * @return int Returns 1 if the string is valid, 0 otherwise.
 */
int					check_digit_and_sign(char *str);

/**
 * @brief Checks if the given string represents a number within the valid range.
 *
 * @param str The string to check.
 * @return int Returns 1 if the number is within range, 0 otherwise.
 */
int					check_range(char *str);

/**
 * @brief Validates the command-line arguments.
 *
 * @param argv The array of command-line arguments.
 * @return int Returns 1 if all entries are valid, 0 otherwise.
 */
int					check_entry(char *argv[]);

/**
 * @brief Checks for duplicate entries in the command-line arguments.
 *
 * @param str The string to check for duplicates.
 * @param argv The array of command-line arguments.
 * @param index The current index in the array.
 * @return int Returns 1 if a duplicate is found, 0 otherwise.
 */
int					check_duplicate(char *str, char *argv[], int index);

// sorting.c

/**
 * @brief Get the maximum value in the stack.
 *
 * @param stack The stack to search.
 * @return The maximum value in the stack.
 */
int get_max(t_stack stack);

/**
 * @brief Get the minimum value in the stack.
 *
 * @param stack The stack to search.
 * @return The minimum value in the stack.
 */
int get_min(t_stack stack);

/**
 * @brief Search for the index of a value in stack_b.
 *
 * @param value The value to search for.
 * @param stack_b The stack to search in.
 * @return The index of the value in stack_b, or -1 if not found.
 */
int search_index(int value, t_stack *stack_b);

/**
 * @brief Search for the index of the maximum value in stack_b.
 *
 * @param stack The stack to search in.
 * @return The index of the maximum value in stack_b.
 */
int search_max_index(t_stack *stack);

/**
 * @brief Perform a move operation on the stacks.
 *
 * @param move The move to perform.
 * @param stack_a The first stack.
 * @param stack_b The second stack.
 */
void do_move(t_move *move, t_stack *stack_a, t_stack *stack_b);

/**
 * @brief Determine the best move to perform.
 *
 * @param move The move to determine.
 */
void best_move(t_move *move);

/**
 * @brief Sort the elements in stack_a using stack_b as auxiliary.
 *
 * @param stack_a The stack to sort.
 * @param stack_b The auxiliary stack.
 */
void sorting(t_stack *stack_a, t_stack *stack_b);

#endif
