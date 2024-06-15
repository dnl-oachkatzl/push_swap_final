/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:17:19 by daspring          #+#    #+#             */
/*   Updated: 2024/06/15 18:02:20 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

void	init_stack(t_stack *stack);
void	init_input(t_input *input, int argc, char **argv);
void	process_input(t_input *input, t_memories *memories);
int		ft_atoi_mod(const char *str);
void	termination(void);
void	fatal_termination(t_memories *memories, int argc);
void	free_argv_as_words(char ***argv_as_words, int argc);
void	free_input(t_input *input);
void	free_stack(t_stack *stack);
void	free_memories(t_memories *memories, int argc);

#endif
