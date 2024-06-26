/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:13:18 by daspring          #+#    #+#             */
/*   Updated: 2024/06/26 15:07:56 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "../includes/doubly_linked_list.h"
#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack		stack_a;
	t_stack		stack_b;
	t_input		input;
	t_memories	memories;

	init_input(&input, argc, argv);
	init_stack(&stack_a);
	init_stack(&stack_b);
	init_memories(&memories, &input, &stack_a, &stack_b);
	process_input(&input, &memories);
	play_the_game(&stack_a, &stack_b, &input, &memories);
	free_memories(&memories, argc);
	return (EXIT_SUCCESS);
}
