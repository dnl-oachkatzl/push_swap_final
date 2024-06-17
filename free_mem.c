/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:27:00 by daspring          #+#    #+#             */
/*   Updated: 2024/06/17 15:56:40 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "push_swap.h"
#include "doubly_linked_list.h"

void	free_memories(t_memories *memories, int argc)
{
	if (memories->argv_as_words != NULL)
	{
		free_argv_as_words(memories->argv_as_words, argc);
		memories->argv_as_words = NULL;
	}
	free_stack(memories->a_stack);
	free_stack(memories->b_stack);
	free_input(memories->input);
}

void	free_argv_as_words(char ***argv_as_words, int argc)
{
	int	pos;

	while (argc > 1)
	{
		pos = 0;
		while (argv_as_words[argc - 2][pos])
		{
			free(argv_as_words[argc - 2][pos]);
			pos++;
		}
		free(argv_as_words[argc - 2]);
		argc--;
	}
	free(argv_as_words);
}

void	free_stack(t_stack *stack)
{
	delete_stack(stack);
}

void	free_input(t_input *input)
{
	if (input->unsorted_input != NULL)
	{
		free(input->unsorted_input);
		input->unsorted_input = NULL;
	}
	if (input->sorted_input != NULL)
	{
		free(input->sorted_input);
		input->sorted_input = NULL;
	}
}
