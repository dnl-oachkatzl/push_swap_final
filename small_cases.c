/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_cases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:14:47 by daspring          #+#    #+#             */
/*   Updated: 2024/06/18 17:26:56 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "rules.h"

void	case1(t_input *input, t_memories *memories)
{
	termination(memories, input->argc);
}

void	case2(t_stack *stack_a, t_stack *stack_b, t_input *input, \
				t_memories *memories)
{
	if (input->sorted_input[0] < input->sorted_input[1])
		termination(memories, input->argc);
	else
	{
		sa(stack_a);
		termination(memories, input->argc);
	}
}
