/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:06:11 by daspring          #+#    #+#             */
/*   Updated: 2024/06/26 15:07:56 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "../includes/doubly_linked_list.h"

void	sa(t_stack *stack_a)
{
	t_dl_node	*node_first;
	t_dl_node	*node_second;

	node_first = extract_node(stack_a, TOP);
	node_second = extract_node(stack_a, TOP);
	insert_node(node_first, stack_a, TOP);
	insert_node(node_second, stack_a, TOP);
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack_b)
{
	t_dl_node	*node_first;
	t_dl_node	*node_second;

	node_first = extract_node(stack_b, TOP);
	node_second = extract_node(stack_b, TOP);
	insert_node(node_first, stack_b, TOP);
	insert_node(node_second, stack_b, TOP);
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	t_dl_node	*node_first;
	t_dl_node	*node_second;

	node_first = extract_node(stack_a, TOP);
	node_second = extract_node(stack_a, TOP);
	insert_node(node_first, stack_a, TOP);
	insert_node(node_second, stack_a, TOP);
	node_first = extract_node(stack_b, TOP);
	node_second = extract_node(stack_b, TOP);
	insert_node(node_first, stack_b, TOP);
	insert_node(node_second, stack_b, TOP);
	write(1, "sr\n", 3);
}
