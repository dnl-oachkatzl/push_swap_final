/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 18:27:31 by daspring          #+#    #+#             */
/*   Updated: 2024/06/18 17:03:23 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "doubly_linked_list.h"
#include "push_swap.h"
#include "libft/libft.h"

static char	***create_words_out_of_argv(char *argv[], int argc, \
										t_memories *memories);
static int	count_words(char ***argv_as_words, int argc);
static void	put_ints_into_unsorted_array(t_input *input, char ***argv_as_words, \
										int argc, t_memories *memories);
static void	pre_sort_and_check_duplicates(t_input *input, t_memories *memories);

void	process_input(t_input *input, t_memories *memories)
{
	if (input->argc == 1)
		fatal_termination(memories, input->argc);
	memories->argv_as_words = create_words_out_of_argv(input->argv, \
													input->argc, memories);
	input->num_of_entries = count_words(memories->argv_as_words, input->argc);
	ft_printf("number of words: %d\n", input->num_of_entries);
	input->unsorted_input = malloc(input->num_of_entries * sizeof(int));
	input->sorted_input = malloc(input->num_of_entries * sizeof(int));
	if (input->unsorted_input == NULL || input->sorted_input == NULL)
		fatal_termination(memories, input->argc);
	put_ints_into_unsorted_array(input, memories->argv_as_words, input->argc, \
							memories);
	pre_sort_and_check_duplicates(input, memories);
	free_argv_as_words(memories->argv_as_words, input->argc);
	memories->argv_as_words = NULL;
}

static char	***create_words_out_of_argv(char *argv[], int argc, \
										t_memories *memories)
{
	char	***argv_as_words;
	int		pos;

	argv_as_words = malloc((argc - 1) * sizeof(char *));
	if (argv_as_words == NULL)
		fatal_termination(memories, argc);
	pos = 0;
	while (pos < argc - 1)
	{
		argv_as_words[pos] = ft_split(argv[pos + 1], ' ');
		if (argv_as_words[pos] == NULL)
			fatal_termination(memories, argc);
		pos++;
	}
	return (argv_as_words);
}

static int	count_words(char ***argv_as_words, int argc)
{
	int	number_of_words;
	int	pos;

	number_of_words = 0;
	while (argc > 1)
	{
		pos = 0;
		while (argv_as_words[argc - 2][pos])
		{
			number_of_words++;
			pos++;
		}
		argc--;
	}
	return (number_of_words);
}

static void	put_ints_into_unsorted_array(t_input *input, \
				char ***argv_as_words, int argc, t_memories *memories)
{
	int	idx;
	int	pos;
	int	array_idx;

	idx = 0;
	array_idx = 0;
	while (idx < argc - 1)
	{
		pos = 0;
		while (argv_as_words[idx][pos])
		{
			input->unsorted_input[array_idx] = \
				ft_atoi_mod(argv_as_words[idx][pos], memories, argc);
			array_idx++;
			pos++;
		}
		idx++;
	}
}

static void	pre_sort_and_check_duplicates(t_input *input, t_memories *memories)
{
	int	pos1;
	int	pos2;
	int	examined_number;
	int	occurence_of_examined_number;
	int	counting_nums_smaller_than_examined;

	pos1 = 0;
	while (pos1 < input->num_of_entries)
	{
		examined_number = input->unsorted_input[pos1];
		occurence_of_examined_number = 0;
		counting_nums_smaller_than_examined = 0;
		pos2 = 0;
		while (pos2 < input->num_of_entries)
		{
			if (input->unsorted_input[pos2++] < examined_number)
				counting_nums_smaller_than_examined++;
			else if (input->unsorted_input[pos2++] == examined_number)
				occurence_of_examined_number++;
			if (occurence_of_examined_number > 1)
				fatal_termination(memories, input->argc);
			input->sorted_input[pos1++] = counting_nums_smaller_than_examined;
		}
	}
}
