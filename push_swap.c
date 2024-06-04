/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:13:18 by daspring          #+#    #+#             */
/*   Updated: 2024/06/04 10:41:35 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "doubly_linked_list.h"
#include "push_swap.h"

int	main(int argc, char *argv[])
{
	// check_input
	// create stack_a
	// print stack_a

	// int		input[] = {1, 2, 3, 4};
	t_stack	a_stack;
	t_stack	b_stack;
	t_input	*input;

	input = malloc(sizeof(t_input));
	init_stack(&a_stack);
	init_stack(&b_stack);
	process_input(input, argc, argv);
	for (int i = 0; i < argc - 1; i++)
	{
		printf("%d\n", input->unsorted_input[i]);
	}
	return (0);
}
