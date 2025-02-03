/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:16:06 by vbonnard          #+#    #+#             */
/*   Updated: 2025/02/03 10:56:00 by vbonnard         ###   ########.fr       */
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

/**
 * @brief Frees the memory allocated for a split string array.
 *
 * This function takes a double pointer to a character array (split) and frees
 * all the memory allocated for each string in the array, as well as the memory
 * allocated for the array itself.
 *
 * @param split A double pointer to the array of strings to be freed.
 */
void	free_split(char **split);

// tool.c

/**
 * @brief Gets the maximum value in the stack.
 *
 * @param stack The stack to search.
 * @return The maximum value in the stack.
 */
int					get_max(t_stack stack);

/**
 * @brief Gets the minimum value in the stack.
 *
 * @param stack The stack to search.
 * @return The minimum value in the stack.
 */
int					get_min(t_stack stack);

/**

	* @brief Searches for the index of the closest value less than the given value in stack_b.
 *
 * @param value The value to compare against.
 * @param stack_b The stack to search.
 * @return The index of the closest value less than the given value.
 */
int					search_index(int value, t_stack *stack_b);

/**
 * @brief Searches for the index of the maximum value in the stack.
 *
 * @param stack The stack to search.
 * @return The index of the maximum value in the stack.
 */
int					search_max_index(t_stack *stack);

// tool_2.c
/**
 * @brief Applies rotation moves to both stacks.
 *
 * @param move The move structure containing the number of rotations.
 * @param stack_a The first stack to rotate.
 * @param stack_b The second stack to rotate.
 */
void				apply_rotation(t_move *move, t_stack *stack_a,
						t_stack *stack_b);

/**
 * @brief Applies reverse rotation moves to both stacks.
 *
 * @param move The move structure containing the number of reverse rotations.
 * @param stack_a The first stack to reverse rotate.
 * @param stack_b The second stack to reverse rotate.
 */
void				apply_reverse_rotation(t_move *move, t_stack *stack_a,
						t_stack *stack_b);

/**
 * @brief Executes the moves on the stacks.
 *
 * @param move The move structure containing the moves to execute.
 * @param stack_a The first stack to apply the moves to.
 * @param stack_b The second stack to apply the moves to.
 */
void				do_move(t_move *move, t_stack *stack_a, t_stack *stack_b);

// sorting.c
/**
 * @brief Updates the move structure with the best move.
 *
 * @param temp The temporary move structure to update.
 * @param cost The 4 rotations structure.
 * @param best The current best cost to compare against.
 */
// void	update_move(t_move *temp, int ra, int rb, int rra, int rrb, int *best);
void	update_move(t_move *temp, t_move move, int *best);


/**
 * @brief Determines the best move to perform.
 *
 * @param move The move structure to update with the best move.
 */
void				best_move(t_move *move);

/**
 * @brief Calculates the move for a given node in stack a.
 *
 * @param stack_a The first stack.
 * @param temp The current node in stack a.
 * @param stack_b The second stack.
 * @param temp_move The temporary move structure to update.
 */
void	calculate_move(t_stack *stack_a, t_node *temp, t_stack *stack_b,
		t_move *temp_move, int index_a);
/**
 * @brief Selects the best move to perform from stack a to stack b.
 *
 * @param stack_a The first stack.
 * @param stack_b The second stack.
 * @param move The move structure to update with the best move.
 */
void				select_best_move(t_stack *stack_a, t_stack *stack_b,
						t_move *move);

/**
 * @brief Sorts the elements in stack a using stack b.
 *
 * @param stack_a The first stack to sort.
 * @param stack_b The second stack used for sorting.
 */
void				sorting(t_stack *stack_a, t_stack *stack_b);

// tool_3.c
/**
 * @brief Solves the sorting problem for the given stacks.
 *
 * @param stack_a The first stack to sort.
 * @param stack_b The second stack used for sorting.
 */
void				solve(t_stack *stack_a, t_stack *stack_b);

/**
 * @brief Sorts a stack of 3 elements.
 *
 * @param stack_a The stack to sort.
 */
void				ps_sort_3(t_stack *stack_a);

/**
 * @brief Sorts a stack of 4 elements.
 *
 * @param stack_a The stack to sort.
 * @param stack_b The auxiliary stack used for sorting.
 */
void				ps_sort_4(t_stack *stack_a, t_stack *stack_b);

/**
 * @brief Sorts a stack of 5 elements.
 *
 * @param stack_a The stack to sort.
 * @param stack_b The auxiliary stack used for sorting.
 */
void				ps_sort_5(t_stack *stack_a, t_stack *stack_b);
#endif
