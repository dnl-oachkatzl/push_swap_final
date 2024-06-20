/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_cases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:14:47 by daspring          #+#    #+#             */
/*   Updated: 2024/06/20 19:01:04 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include "rules.h"

void	case1(t_input *input, t_memories *memories)
{
	;
}

void	case2(t_stack *stack_a, t_stack *stack_b, t_input *input, \
				t_memories *memories)
{
	if (input->sorted_input[0] < input->sorted_input[1])
		;
	else
		sa(stack_a);
}

void	case3(t_stack *stack_a, t_stack *stack_b, t_input *input, \
				t_memories *memories)
{
	if (input->sorted_input[2] == 2)
		case2(stack_a, stack_b, input, memories);
	else if (input->sorted_input[0] == 2)
	{
		ra(stack_a);
		array_del_entry(input->sorted_input, 0, input->num_of_entries);
		case2(stack_a, stack_b, input, memories);
	}
	else if (input->sorted_input[0] == 0)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (input->sorted_input[0] == 1)
		rra(stack_a);
}

// void	case4(t_stack *stack_a, t_stack *stack_b, t_input *input, \
// 				t_memories *memories)
// {
// 	int	index_of_zero;
//
// 	index_of_zero = find_index_of_zero(input);
// 	if (index_of_zero == 0)
// 	{
// 		pb(stack_a, stack_b);
// 		array_del_entry(input->sorted_input, 0, input->num_of_entries);
// 		array_decrement_by_one(input->sorted_input, input->num_of_entries);
// 		case3(stack_a, stack_b, input, memories);
// 		pa(stack_a, stack_b);
// 	}
// 	else if (index_of_zero == 1)
// 	{
// 		ra(stack_a);
// 		array_del_entry(input->sorted_input, 1, input->num_of_entries);
// 		array_decrement_by_one(input->sorted_input, input->num_of_entries);
// 		pb(stack_a, stack_b);
// 		case3(stack_a, stack_b, input, memories);
// 		pa(stack_a, stack_b);
// 	}
// 	else if (index_of_zero == 2)
// 	{
// 		ra(stack_a);
// 		ra(stack_a);
// 		pb(stack_a, stack_b);
// 		array_del_entry(input->sorted_input, 1, input->num_of_entries);
// 		array_decrement_by_one(input->sorted_input, input->num_of_entries);
// 		case3(stack_a, stack_b, input, memories);
// 		pa(stack_a, stack_b);
// 	}
// 	else if (index_of_zero == 3)
// 	{
// 		rra(stack_a);
// 		pb(stack_a, stack_b);
// 		case3(stack_a, stack_b, input, memories);
// 		pa(stack_a, stack_b);
// 	}
// }

// void	case4(t_stack *stack_a, t_stack *stack_b, t_input *input, \
// 				t_memories *memories)
// {
// 	int	index_of_zero;
//
// 	index_of_zero = find_index_of_zero(input);
// 	if (index_of_zero == 0)
// 	{
// 		pb(stack_a, stack_b);
// 		array_del_entry(input->sorted_input, 0, input->num_of_entries);
// 		array_decrement_by_one(input->sorted_input, input->num_of_entries);
// 		case3(stack_a, stack_b, input, memories);
// 		pa(stack_a, stack_b);
// 	}
// 	else if (index_of_zero == 1)
// 	{
// 		ra(stack_a);
// 		ra_for_array(input->sorted_input, input->num_of_entries);
// 		case4(stack_a, stack_b, input, memories);
// 	}
// 	else if (index_of_zero == 2)
// 	{
// 		ra(stack_a);
// 		ra_for_array(input->sorted_input, input->num_of_entries);
// 		case4(stack_a, stack_b, input, memories);
// 	}
// 	else if (index_of_zero == 3)
// 	{
// 		rra(stack_a);
// 		pb(stack_a, stack_b);
// 		case3(stack_a, stack_b, input, memories);
// 		pa(stack_a, stack_b);
// 	}
// }

void	case4(t_stack *stack_a, t_stack *stack_b, t_input *input, \
				t_memories *memories)
{
	int	index_of_zero;

	index_of_zero = find_index_of_zero(input);
	if (index_of_zero == 0)
	{
		pb(stack_a, stack_b);
		array_del_entry(input->sorted_input, 0, input->num_of_entries);
		array_decrement_by_one(input->sorted_input, input->num_of_entries);
		case3(stack_a, stack_b, input, memories);
		pa(stack_a, stack_b);
	}
	else
	{
		ra(stack_a);
		ra_for_array(input->sorted_input, input->num_of_entries);
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
		array_del_entry(input->sorted_input, 0, input->num_of_entries);
		array_decrement_by_one(input->sorted_input, input->num_of_entries);
		case4(stack_a, stack_b, input, memories);
		pa(stack_a, stack_b);
	}
	else
	{
		ra(stack_a);
		ra_for_array(input->sorted_input, input->num_of_entries);
		case5(stack_a, stack_b, input, memories);
	}
}

