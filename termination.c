/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termination.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:59:58 by daspring          #+#    #+#             */
/*   Updated: 2024/06/15 18:31:44 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft/libft.h"
#include "push_swap.h"

void	termination(void)
{
	exit(EXIT_SUCCESS);
}

void	fatal_termination(t_memories *memories, int argc)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
