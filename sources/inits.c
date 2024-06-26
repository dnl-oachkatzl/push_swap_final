/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 19:10:58 by daspring          #+#    #+#             */
/*   Updated: 2024/06/26 15:07:56 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "../includes/doubly_linked_list.h"
#include "../includes/push_swap.h"

void	init_stack(t_stack *stack)
{
	stack->head = NULL;
	stack->tail = NULL;
	stack->number_of_elements = 0;
}

void	init_input(t_input *input, int argc, char **argv)
{
	input->argc = argc;
	input->argv = argv;
	input->num_of_entries = 0;
	input->unsorted_input = NULL;
	input->sorted_input = NULL;
}

void	init_memories(t_memories *memories, t_input *input, t_stack *a_stack, \
				t_stack *b_stack)
{
	memories->input = input;
	memories->a_stack = a_stack;
	memories->b_stack = b_stack;
	memories->argv_as_words = NULL;
}
