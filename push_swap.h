/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:17:19 by daspring          #+#    #+#             */
/*   Updated: 2024/05/28 19:32:12 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "doubly_linked_list.h"

typedef struct s_input
{
	int	*unsorted_input;
	int	input_has_errors;
}	t_input;

void	init_stack(t_stack *stack);
void	process_input(t_input *input, int argc, char *argv[]);

#endif
