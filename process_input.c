/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 18:27:31 by daspring          #+#    #+#             */
/*   Updated: 2024/06/12 17:55:33 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#include "doubly_linked_list.h"
#include "push_swap.h"

#include <stddef.h>

static void	check_leading_chars(const char *str, size_t *pos, int *signum);
static int	ft_atoi_mod(t_input *input, const char *str);

void	process_input(t_input *input, int argc, char *argv[])
{
	if (argc == 1)
	{
		input->input_has_errors = 1;
		return ;
	}
	// put words into char*[]
	// count words
	input->unsorted_input = malloc((argc - 1) * sizeof(int));
	if (input->unsorted_input == NULL)
	{
		input->input_has_errors = 1;
		return ;
	}
	// put ints into array
	// sort pre-sort-array
	while (--argc >= 1)
		{
		input->unsorted_input[argc - 1] = ft_atoi_mod(input, argv[argc]);
		input->num_of_entries++;
		}
}

static int	ft_atoi_mod(t_input *input, const char *str)
{
	unsigned long long	number;
	size_t				pos;
	int					signum;

	number = 0;
	pos = 0;
	signum = 1;
	check_leading_chars(str, &pos, &signum);
	while (str[pos] >= '0' && str[pos] <= '9')
	{
		number = (number * 10) + (str[pos] - '0');
		pos++;
		if (number > INT_MAX)
		{
			input->input_has_errors = 1;
			return (-1);
		}
	}
	while (str[pos] != '\0')
	{
		if (!(str[pos] == ' ' || str[pos] == '\t' || str[pos] == '\n' || str[pos] == '\v' || str[pos] == '\f' || str[pos] == '\r'))
		{
			input->input_has_errors = 1;
			return (-1);
		}
		pos++;
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
