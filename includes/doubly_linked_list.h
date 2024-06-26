/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:05:41 by daspring          #+#    #+#             */
/*   Updated: 2024/06/18 12:15:40 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLY_LINKED_LIST_H
# define DOUBLY_LINKED_LIST_H

# define TOP 1
# define BOTTOM -1

typedef struct s_dl_node
{
	int					value;
	int					rel_value;
	struct s_dl_node	*previous;
	struct s_dl_node	*next;
}						t_dl_node;

typedef struct s_stack
{
	t_dl_node	*head;
	t_dl_node	*tail;
	int			number_of_elements;
}				t_stack;

t_dl_node	*create_node(int value, int rel_value);
void		insert_node(t_dl_node *node, t_stack *stack, int position);

/**	@brief removes a node from a given list, either from head or from tail
 *
 *	@param stack from which to remove
 *	@param position either TOP or BOTTOM
 *
 *	@return the removed node
 */
t_dl_node	*extract_node(t_stack *stack, int position);
void		delete_stack(t_stack *stack);

#endif
