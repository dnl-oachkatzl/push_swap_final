/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:13:18 by daspring          #+#    #+#             */
/*   Updated: 2024/06/19 16:47:45 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "doubly_linked_list.h"
#include "push_swap.h"
#include "libft/libft.h"
#include "testing/test_fts.h"

int	main(int argc, char *argv[])
{
	t_stack		stack_a;
	t_stack		stack_b;
	t_input		input;
	t_memories	memories;

	init_input(&input, argc, argv);
	init_stack(&stack_a);
	init_stack(&stack_b);
	init_memories(&memories, &input, &stack_a, &stack_b);
	process_input(&input, &memories);
	play_the_game(&stack_a, &stack_b, &input, &memories);
	// print_int_array(input.unsorted_input, input.num_of_entries);
	// print_int_array(input.sorted_input, input.num_of_entries);
	// print_single_stack(&stack_a);
	free_memories(&memories, argc);
	return (EXIT_SUCCESS);
}
