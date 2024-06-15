/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 18:27:31 by daspring          #+#    #+#             */
/*   Updated: 2024/06/15 18:40:06 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stddef.h>

#include "doubly_linked_list.h"
#include "push_swap.h"

static void	check_leading_chars(const char *str, size_t *pos, int *signum);

void	init_stack(t_stack *stack)
{
	stack->head = NULL;
	stack->tail = NULL;
	stack->number_of_elements = 0;
}

void	init_input(t_input *input, int argc, char **argv)
{
	input->argc = argc;
	input->argv = argv;
	input->num_of_entries = 0;
}

// int	ft_atoi_mod(const char *str)
// {
// 	unsigned long long	number;
// 	size_t				pos;
// 	int					signum;
//
// 	number = 0;
// 	pos = 0;
// 	signum = 1;
// 	check_leading_chars(str, &pos, &signum);
// 	while (str[pos] >= '0' && str[pos] <= '9')
// 	{
// 		number = (number * 10) + (str[pos] - '0');
// 		pos++;
// 		if (number > INT_MAX)
// 			fatal_termination();
// 	}
// 	while (str[pos] != '\0')
// 	{
// 		if (!(str[pos] == ' ' || str[pos] == '\t' || str[pos] == '\n' || str[pos] == '\v' || str[pos] == '\f' || str[pos] == '\r'))
// 			fatal_termination();
// 		pos++;
// 	}
// 	return ((int)(signum * number));
// }
//
static void	check_leading_chars(const char *str, size_t *pos, int *signum)
{
	while (str[*pos] == ' ' || str[*pos] == '\t' || str[*pos] == '\n'\
	|| str[*pos] == '\v' || str[*pos] == '\f' || str[*pos] == '\r')
		(*pos)++;
	if (str[*pos] == '+' || str[*pos] == '-')
	{
		if (str[*pos] == '-')
			*signum = -1;
		(*pos)++;
	}
	while (str[*pos] == '0')
		(*pos)++;
}
