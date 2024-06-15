/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:13:18 by daspring          #+#    #+#             */
/*   Updated: 2024/06/15 18:51:51 by daspring         ###   ########.fr       */
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
	// check_input
	// create stack_a
	// print stack_a

	// int		input[] = {1, 2, 3, 4};
	t_stack	a_stack;
	t_stack	b_stack;
	t_input	input;
	t_memories	memories;

	init_input(&input, argc, argv);
	init_stack(&a_stack);
	init_stack(&b_stack);


	memories.input = &input;
	memories.a_stack = &a_stack;
	memories.b_stack = &b_stack;


	process_input(&input, &memories);
	fill_stack_a(&a_stack, &input);
	print_single_stack(&a_stack);
	// for (int i = 0; i < argc - 1; i++)
	// {
	// 	ft_printf("%d\n", input->unsorted_input[i]);
	// }
	free_memories(&memories, argc);
	return (EXIT_SUCCESS);
}
