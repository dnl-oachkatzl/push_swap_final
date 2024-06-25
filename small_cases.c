/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_cases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:14:47 by daspring          #+#    #+#             */
/*   Updated: 2024/06/25 13:34:30 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "rules.h"

void	case1(void)
{
	return ;
}

void	case2(t_stack *stack_a, t_input *input)
{
	if (input->sorted_input[0] < input->sorted_input[1])
		;
	else
		sa(stack_a);
}

void	case3(t_stack *stack_a, t_input *input)
{
	if (input->sorted_input[2] == 2)
		case2(stack_a, input);
	else if (input->sorted_input[0] == 2)
	{
		ra(stack_a);
		array_del_entry(input->sorted_input, 0, 3);
		case2(stack_a, input);
	}
	else if (input->sorted_input[0] == 0)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (input->sorted_input[0] == 1)
		rra(stack_a);
}

void	case4(t_stack *stack_a, t_stack *stack_b, t_input *input, \
				t_memories *memories)
{
	int	index_of_zero;

	index_of_zero = find_index_of_zero(input);
	if (index_of_zero == 0)
	{
		pb(stack_a, stack_b);
		array_del_entry(input->sorted_input, 0, 4);
		array_decrement_by_one(input->sorted_input, 4);
		case3(stack_a, input);
		pa(stack_a, stack_b);
	}
	else
	{
		ra(stack_a);
		ra_for_array(input->sorted_input, 4);
		case4(stack_a, stack_b, input, memories);
	}
}

void	case5(t_stack *stack_a, t_stack *stack_b, t_input *input, \
				t_memories *memories)
{
	int	index_of_zero;

	index_of_zero = find_index_of_zero(input);
	if (index_of_zero == 0)
	{
		pb(stack_a, stack_b);
		array_del_entry(input->sorted_input, 0, 5);
		array_decrement_by_one(input->sorted_input, 5);
		case4(stack_a, stack_b, input, memories);
		pa(stack_a, stack_b);
	}
	else if (index_of_zero == 4)
	{
		rra(stack_a);
		rra_for_array(input->sorted_input, 5);
		case5(stack_a, stack_b, input, memories);
	}
	else
	{
		ra(stack_a);
		ra_for_array(input->sorted_input, 5);
		case5(stack_a, stack_b, input, memories);
	}
}
