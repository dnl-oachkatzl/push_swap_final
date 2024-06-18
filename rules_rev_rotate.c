/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rev_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:35:58 by daspring          #+#    #+#             */
/*   Updated: 2024/06/18 15:49:26 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "doubly_linked_list.h"

void	rra(t_stack *stack_a)
{
	t_dl_node	*node;

	node = extract_node(stack_a, BOTTOM);
	insert_node(node, stack_a, TOP);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack_b)
{
	t_dl_node	*node;

	node = extract_node(stack_b, BOTTOM);
	insert_node(node, stack_b, TOP);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	t_dl_node	*node;

	node = extract_node(stack_b, BOTTOM);
	insert_node(node, stack_b, TOP);
	node = extract_node(stack_a, BOTTOM);
	insert_node(node, stack_a, TOP);
	write(1, "rrr\n", 4);
}
