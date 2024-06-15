/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:17:19 by daspring          #+#    #+#             */
/*   Updated: 2024/06/15 15:06:35 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "doubly_linked_list.h"

typedef struct s_input
{
	int	*unsorted_input;
	int	*sorted_input;
	int	num_of_entries;
	int	input_has_errors;
}	t_input;

void	init_stack(t_stack *stack);
void	process_input(t_input *input, int argc, char *argv[]);
void	termination(void);
void	fatal_termination(void);
int		ft_atoi_mod(const char *str);
void	free_argv_as_words(char ***argv_as_words, int argc);

#endif
