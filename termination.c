/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termination.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:59:58 by daspring          #+#    #+#             */
/*   Updated: 2024/06/18 17:17:49 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft/libft.h"
#include "push_swap.h"

void	termination(t_memories *memories, int argc)
{
	free_memories(memories, argc);
	exit(EXIT_SUCCESS);
}

void	fatal_termination(t_memories *memories, int argc)
{
	ft_putstr_fd("Error\n", 2);
	free_memories(memories, argc);
	exit(EXIT_FAILURE);
}
