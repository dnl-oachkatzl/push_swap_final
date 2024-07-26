/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:42:16 by daspring          #+#    #+#             */
/*   Updated: 2024/07/26 14:26:56 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doubly_linked_list.h"
#include "../includes/push_swap.h"

void	play_the_game(t_stack *stack_a, t_stack *stack_b, t_input *input, \
					t_memories *memories)
{
	fill_stack_a(stack_a, input);
	if (check_if_sorted(stack_a))
		return ;
	if (input->num_of_entries == 1)
		case1();
	else if (input->num_of_entries == 2)
		case2(stack_a, input);
	else if (input->num_of_entries == 3)
		case3(stack_a, input);
	else if (input->num_of_entries == 4)
		case4(stack_a, stack_b, input, memories);
	else if (input->num_of_entries == 5)
		case5(stack_a, stack_b, input, memories);
	else
	{
		radix_sort(stack_a, stack_b);
	}
}
