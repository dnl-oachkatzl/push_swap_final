/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:08:07 by daspring          #+#    #+#             */
/*   Updated: 2024/06/26 15:07:56 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/rules.h"

static int	calculate_length_of_binary(t_stack *stack_a);

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	length_of_binary;
	int	pos_in_binary;
	int	pos_in_stack;

	length_of_binary = calculate_length_of_binary(stack_a);
	pos_in_binary = 0;
	while (pos_in_binary < length_of_binary)
	{
		pos_in_stack = 0;
		while (pos_in_stack < stack_a->number_of_elements)
		{
			if ((stack_a->head->rel_value >> pos_in_binary & 1) == 0)
				pb(stack_a, stack_b);
			else
			{
				ra(stack_a);
				pos_in_stack++;
			}
		}
		while (0 < stack_b->number_of_elements)
			pa(stack_a, stack_b);
		pos_in_binary++;
	}
}

static int	calculate_length_of_binary(t_stack *stack_a)
{
	int	exponent;

	exponent = 0;
	while (1)
	{
		if (stack_a->number_of_elements <= 1 << exponent)
			return (exponent);
		else
			exponent++;
	}
}
