/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:16:56 by daspring          #+#    #+#             */
/*   Updated: 2024/05/28 19:59:42 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stddef.h>
#include <stdlib.h>

#include "doubly_linked_list.h"

/*
 *	DELETE STACK DOES NOT YET WORK
 */



/**	@brief creates a new node
 *
 *	caller must free the returned node after use!
 *
 *	@param data takes any type of data as content
 *	@return a node of type t_dl_list
 */
t_dl_list	*create_node(void *data)
{
	t_dl_list	*new_node;

	new_node = malloc(1 * sizeof(t_dl_list));
	if (new_node == NULL)
		return (NULL);
	new_node->next = NULL;
	new_node->previous = NULL;
	new_node->content = data;
	return (new_node);
}

void	delete_node(t_dl_list *node)
{
	free(node->content);
	free(node->previous);
	free(node->next);
	free(node);
}

void	insert_node(t_dl_list *node, t_stack *stack, int position)
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

t_dl_list	*extract_node(t_stack *stack, int position)
{
	t_dl_list	*node;

	if (position == TOP)
	{
		node = stack->head;
		stack->head = node->next;
		stack->head->previous = NULL;
	}
	else
	{
		node = stack->tail;
		stack->tail = node->previous;
		stack->tail->next = NULL;
	}
	stack->number_of_elements--;
	node->previous = NULL;
	node->next = NULL;
	return (node);
}

void	delete_stack(t_stack *stack)
{
	t_dl_list	*current_node;

	current_node = stack->head;
	stack->head = stack->head->next;
	delete_node(current_node);
}
