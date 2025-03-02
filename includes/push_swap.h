/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:17:19 by daspring          #+#    #+#             */
/*   Updated: 2024/07/26 14:25:28 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>

# include "doubly_linked_list.h"

typedef struct s_input
{
	int		*unsorted_input;
	int		*sorted_input;
	int		num_of_entries;
	int		argc;
	char	**argv;
}	t_input;

typedef struct s_memories
{
	char	***argv_as_words;
	t_input	*input;
	t_stack	*a_stack;
	t_stack	*b_stack;
}	t_memories;

typedef struct s_input_string_data
{
	char	*str;
	size_t	pos;
	int		signum;
}			t_input_string_data;

void	init_stack(t_stack *stack);
void	init_input(t_input *input, int argc, char **argv);
void	init_memories(t_memories *memories, t_input *input, t_stack *a_stack, \
				t_stack *b_stack);

void	process_input(t_input *input, t_memories *memories);
int		ft_atoi_mod(const char *str, t_memories *memories, int argc);
void	fill_stack_a(t_stack *stack_a, t_input *input);

void	play_the_game(t_stack *stack_a, t_stack *stack_b, t_input *input, \
				t_memories *memories);
int		check_if_sorted(t_stack *stack_a);
void	case1(void);
void	case2(t_stack *stack_a, t_input *input);
void	case3(t_stack *stack_a, t_input *input);
void	case4(t_stack *stack_a, t_stack *stack_b, t_input *input, \
				t_memories *memories);
void	case5(t_stack *stack_a, t_stack *stack_b, t_input *input, \
				t_memories *memories);
void	radix_sort(t_stack *stack_a, t_stack *stack_b);

int		find_index_of_zero(t_input *input);
void	array_del_entry(int *array, int idx_entry, int len);
void	ra_for_array(int *array, int len);
void	rra_for_array(int *array, int len);
void	array_decrement_by_one(int *array, int len);

void	termination(t_memories *memories, int argc);
void	fatal_termination(t_memories *memories, int argc);
void	free_argv_as_words(char ***argv_as_words, int argc);
void	free_input(t_input *input);
void	free_stack(t_stack *stack);
void	free_memories(t_memories *memories, int argc);

#endif
