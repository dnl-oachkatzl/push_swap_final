/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 18:27:31 by daspring          #+#    #+#             */
/*   Updated: 2024/06/04 13:35:39 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "doubly_linked_list.h"
#include "push_swap.h"

#include <stddef.h>

static void	check_leading_chars(const char *str, size_t *pos, int *signum);
static int	ft_atoi_mod(const char *str);

void	init_stack(t_stack *stack)
{
	stack->head = NULL;
	stack->tail = NULL;
	stack->number_of_elements = 0;
}

void	process_input(t_input *input, int argc, char *argv[])
{
	// input = malloc(sizeof(t_input));
	if (argc == 1)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	input->unsorted_input = malloc((argc - 1) * sizeof(int));
	if (input->unsorted_input == NULL)
		exit(EXIT_FAILURE);
	while (--argc >= 1)
		input->unsorted_input[argc - 1] = ft_atoi_mod(argv[argc]);
}

int		*check_input(int argc, char *argv[])
{
	int	*value_array;

	value_array = malloc((argc - 1) * sizeof(int));
	while (--argc > 0)
	{
		value_array[argc - 1] = ft_atoi_mod(argv[argc]);
	}
	return (value_array);
}

static int	ft_atoi_mod(const char *str)
{
	unsigned long long	number;
	size_t				pos;
	int					signum;
	int					counter;

	number = 0;
	pos = 0;
	signum = 1;
	counter = 0;
	check_leading_chars(str, &pos, &signum);
	while (str[pos] >= '0' && str[pos] <= '9')
	{
		number = (number * 10) + (str[pos] - '0');
		counter++;
		pos++;
		if (counter > 19 || number > 9223372036854775807)
			return (-1);
	}
	return ((int)(signum * number));
}

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
