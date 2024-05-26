/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:16:56 by daspring          #+#    #+#             */
/*   Updated: 2024/05/26 16:59:19 by daspring         ###   ########.fr       */
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

t_dl_list	*push(t_dl_list *list, int rel_position)
{
	if (list == NULL)
	{
	}
	if (rel_position == BEFORE)
	{
		// is the given node the very first?
		// is the given node the very last?

	}
}

t_dl_list	*pop(t_dl_list *list);

void	delete_stack(t_stack_metadata *stack)
{
	t_dl_list	*current_node;

	current_node = stack->head;
	stack->head = stack->head->next;
	delete_node(current_node);
}
