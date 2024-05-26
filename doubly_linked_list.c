/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:16:56 by daspring          #+#    #+#             */
/*   Updated: 2024/05/26 18:05:28 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

#include "doubly_linked_list.h"
#include "push_swap.h"

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

void	insert_node(t_dl_list *node, t_stack_metadata *stack, int position)
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

t_dl_list	*extract_node(t_stack_metadata *stack, int position)
{
	t_dl_list	*node;
	t_dl_list	*prev;
	t_dl_list	*next;

	if (position == TOP)
		node = stack->head;
	else if (position == BOTTOM)
		node = stack->tail;
	prev = node->previous;
	next = node->next;
	if (prev != NULL)
		prev->next = next;
	if (next != NULL)
		next->previous = prev;
	stack->number_of_elements--;
	return (node);
}

void	delete_stack(t_stack_metadata *stack)
{
	t_dl_list	*current_node;

	current_node = stack->head;
	stack->head = stack->head->next;
	delete_node(current_node);
}
