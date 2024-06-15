/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termination.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:59:58 by daspring          #+#    #+#             */
/*   Updated: 2024/06/13 12:15:58 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft/libft.h"

void	termination(void)
{
	exit(EXIT_SUCCESS);
}

void	fatal_termination(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}
