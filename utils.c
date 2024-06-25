/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 18:27:31 by daspring          #+#    #+#             */
/*   Updated: 2024/06/25 13:27:35 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

#include "doubly_linked_list.h"
#include "push_swap.h"

static void	check_leading_chars(const char *str, size_t *pos, int *signum, \
				t_memories *memories, int argc);

int	ft_atoi_mod(const char *str, t_memories *memories, int argc)
{
	unsigned long long	number;
	size_t				pos;
	int					signum;

	if (NULL)
		fatal_termination(memories, argc);
	number = 0;
	pos = 0;
	signum = 1;
	check_leading_chars(str, &pos, &signum, memories, argc);
	while (str[pos] >= '0' && str[pos] <= '9')
	{
		number = (number * 10) + (str[pos] - '0');
		pos++;
		if (signum == 1 && number > INT_MAX)
			fatal_termination(memories, argc);
		if (signum == -1 && number - 1 > INT_MAX)
			fatal_termination(memories, argc);
	}
	while (str[pos] != '\0')
	{
		if (!(str[pos] == ' ' || str[pos] == '\t' || str[pos] == '\n' \
			|| str[pos] == '\v' || str[pos] == '\f' || str[pos] == '\r'))
			fatal_termination(memories, argc);
		pos++;
	}
	return ((int)(signum * number));
}

static void	check_leading_chars(const char *str, size_t *pos, int *signum, \
				t_memories *memories, int argc)
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
	if (!(str[*pos] >= '0' && str[*pos] <= '9'))
		fatal_termination(memories, argc);
	while (str[*pos] == '0')
		(*pos)++;
}

void	fill_stack_a(t_stack *stack_a, t_input *input)
{
	int			pos;
	t_dl_node	*current_node;

	pos = 0;
	while (pos < input->num_of_entries)
	{
		current_node = create_node(input->unsorted_input[pos], \
							input->sorted_input[pos]);
		insert_node(current_node, stack_a, BOTTOM);
		pos++;
	}
}
