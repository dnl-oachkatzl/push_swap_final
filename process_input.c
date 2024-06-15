/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 18:27:31 by daspring          #+#    #+#             */
/*   Updated: 2024/06/15 18:28:49 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "doubly_linked_list.h"
#include "push_swap.h"
#include "libft/libft.h"


static char	***create_words_out_of_argv(char *argv[], int argc, t_memories *memories);
static int	count_words(char ***argv_as_words, int argc);

void	process_input(t_input *input, t_memories *memories)
{
	int		num_of_words;

	if (input->argc == 1)
		fatal_termination(memories, input->argc);
	memories->argv_as_words = create_words_out_of_argv(input->argv, input->argc, memories);
	num_of_words = count_words(memories->argv_as_words, input->argc);
	ft_printf("number of words: %d\n", num_of_words);
	input->unsorted_input = malloc(num_of_words * sizeof(int));
	input->sorted_input = malloc(num_of_words * sizeof(int));
	if (input->unsorted_input == NULL || input->sorted_input == NULL)
	{
		free_argv_as_words(memories->argv_as_words, input->argc);
		fatal_termination(memories, input->argc);
	}
	// 
	// put ints into array
	// sort pre-sort-array
	// while (--argc >= 1)
	// {
	// 	input->unsorted_input[argc - 1] = ft_atoi_mod(argv[argc]);
	// 	input->num_of_entries++;
	// }
	free_argv_as_words(memories->argv_as_words, input->argc);
	memories->argv_as_words = NULL;
}

static char	***create_words_out_of_argv(char *argv[], int argc, t_memories *memories)
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
