/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:05:41 by daspring          #+#    #+#             */
/*   Updated: 2024/05/27 14:51:06 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLY_LINKED_LIST_H
# define DOUBLY_LINKED_LIST_H

# define TOP 1
# define BOTTOM -1

typedef struct s_dl_list
{
	void				*content;
	struct s_dl_list	*previous;
	struct s_dl_list	*next;
}						t_dl_list;

typedef struct s_stack
{
	t_dl_list	*head;
	t_dl_list	*tail;
	int			number_of_elements;
}				t_stack;

t_dl_list	*create_node(void *data);
void		delete_node(t_dl_list *node);
void		insert_node(t_dl_list *node, t_stack *stack, int position);

/**	@brief removes a node from a given list, either from head or from tail
 *
 *	@param stack
 *	@param position either TOP or BOTTOM
 *
 *	@return the removed node
 */
t_dl_list	*extract_node(t_stack *stack, int position);
void		delete_stack(t_stack *stack);

#endif
