/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:05:41 by daspring          #+#    #+#             */
/*   Updated: 2024/05/26 16:07:04 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLY_LINKED_LIST_H
# define DOUBLY_LINKED_LIST_H

# define BEFORE 1
# define AFTER -1
# define FROM_HEAD 1
# define FREOM_TAIL -1

typedef struct			s_dl_list
{
	void				*content;
	struct s_dl_list	*previous;
	struct s_dl_list	*next;
}						t_dl_list;




#endif
