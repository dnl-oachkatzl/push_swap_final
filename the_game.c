/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:42:16 by daspring          #+#    #+#             */
/*   Updated: 2024/06/20 11:02:57 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doubly_linked_list.h"
#include "push_swap.h"

void	play_the_game(t_stack *stack_a, t_stack *stack_b, t_input *input, \
					t_memories *memories)
{
	fill_stack_a(stack_a, input);
	if (input->num_of_entries == 1)
		case1(input, memories);
	if (input->num_of_entries == 2)
		case2(stack_a, stack_b, input, memories);
	if (input->num_of_entries == 3)
		case3(stack_a, stack_b, input, memories);
	if (input->num_of_entries == 4)
		case4(stack_a, stack_b, input, memories);
}
