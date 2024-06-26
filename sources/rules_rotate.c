/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:35:58 by daspring          #+#    #+#             */
/*   Updated: 2024/06/26 15:07:56 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "../includes/doubly_linked_list.h"

void	ra(t_stack *stack_a)
{
	t_dl_node	*node;

	node = extract_node(stack_a, TOP);
	insert_node(node, stack_a, BOTTOM);
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack_b)
{
	t_dl_node	*node;

	node = extract_node(stack_b, TOP);
	insert_node(node, stack_b, BOTTOM);
	write(1, "rb\n", 3);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	t_dl_node	*node;

	node = extract_node(stack_b, TOP);
	insert_node(node, stack_b, BOTTOM);
	node = extract_node(stack_a, TOP);
	insert_node(node, stack_a, BOTTOM);
	write(1, "rr\n", 3);
}
