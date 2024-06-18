/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:06:11 by daspring          #+#    #+#             */
/*   Updated: 2024/06/18 13:55:52 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "doubly_linked_list.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_dl_node	*node;

	node = extract_node(stack_b, TOP);
	insert_node(node, stack_a, TOP);
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_dl_node	*node;

	node = extract_node(stack_a, TOP);
	insert_node(node, stack_b, TOP);
	write(1, "pb\n", 3);
}
