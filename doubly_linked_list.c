/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:16:56 by daspring          #+#    #+#             */
/*   Updated: 2024/06/18 23:46:24 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "doubly_linked_list.h"

/**	@brief creates a new node
 *
 *	caller must free the returned node after use!
 *
 *	@param data takes any type of data as content
 *	@return a node of type t_dl_node
 */
t_dl_node	*create_node(int value, int rel_value)
{
	t_dl_node	*new_node;

	new_node = malloc(1 * sizeof(t_dl_node));
	if (new_node == NULL)
		return (NULL);
	new_node->next = NULL;
	new_node->previous = NULL;
	new_node->value = value;
	new_node->rel_value = rel_value;
	return (new_node);
}

void	insert_node(t_dl_node *node, t_stack *stack, int position)
{
	if (stack->number_of_elements == 0)
	{
		stack->head = node;
		stack->tail = node;
	}
	else if (position == TOP)
	{
		node->next = stack->head;
		stack->head->previous = node;
		stack->head = node;
	}
	else if (position == BOTTOM)
	{
		node->previous = stack->tail;
		stack->tail->next = node;
		stack->tail = node;
	}
	stack->number_of_elements++;
}

t_dl_node	*extract_node(t_stack *stack, int position)
{
	t_dl_node	*node;

	if (position == TOP)
	{
		node = stack->head;
		stack->head = node->next;
		if (stack->number_of_elements == 1)
			stack->tail = NULL;
		else
			stack->head->previous = NULL;
	}
	else
	{
		node = stack->tail;
		stack->tail = node->previous;
		if (stack->number_of_elements == 1)
			stack->head = NULL;
		else
			stack->tail->next = NULL;
	}
	stack->number_of_elements--;
	node->previous = NULL;
	node->next = NULL;
	return (node);
}

void	delete_stack(t_stack *stack)
{
	t_dl_node	*current_node;
	t_dl_node	*next_node;

	current_node = stack->head;
	while (current_node != NULL)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}
}
