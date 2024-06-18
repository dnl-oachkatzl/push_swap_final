/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:13:18 by daspring          #+#    #+#             */
/*   Updated: 2024/06/18 11:59:35 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "doubly_linked_list.h"
#include "push_swap.h"
#include "libft/libft.h"
#include "testing/test_fts.h"

void	fill_stack_a(t_stack *stack_a, t_input *input)
{
	int			pos;
	t_dl_node	*current_node;

	pos = 0;
	while (pos < input->num_of_entries)
	{
		current_node = create_node(&input->unsorted_input[pos]);
		insert_node(current_node, stack_a, BOTTOM);
		pos++;
	}
}

int	main(int argc, char *argv[])
{
	t_stack	a_stack;
	t_stack	b_stack;
	t_input	input;
	t_memories	memories;

	init_input(&input, argc, argv);
	init_stack(&a_stack);
	init_stack(&b_stack);
	init_memories(&memories, &input, &a_stack, &b_stack);
	process_input(&input, &memories);
	fill_stack_a(&a_stack, &input);
	print_single_stack(&a_stack);
	print_int_array(input.unsorted_input, input.num_of_entries); 
	print_int_array(input.sorted_input, input.num_of_entries); 
	free_memories(&memories, argc);
	return (EXIT_SUCCESS);
}
