/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 18:27:31 by daspring          #+#    #+#             */
/*   Updated: 2024/07/26 14:46:47 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

#include "../includes/doubly_linked_list.h"
#include "../includes/push_swap.h"

static void	check_leading_chars(t_input_string_data *isd, t_memories *memories, \
								int argc);

int	ft_atoi_mod(const char *str, t_memories *memories, int argc)
{
	unsigned long long	number;
	t_input_string_data	isd;

	number = 0;
	isd.str = (char *)str;
	isd.pos = 0;
	isd.signum = 1;
	check_leading_chars(&isd, memories, argc);
	while (isd.str[isd.pos] >= '0' && isd.str[isd.pos] <= '9')
	{
		number = (number * 10) + (isd.str[isd.pos++] - '0');
		if (isd.signum == 1 && number > INT_MAX)
			fatal_termination(memories, argc);
		if (isd.signum == -1 && number - 1 > INT_MAX)
			fatal_termination(memories, argc);
	}
	while (isd.str[isd.pos] != '\0')
	{
		if (!(isd.str[isd.pos] == ' ' || isd.str[isd.pos] == '\t' || \
			isd.str[isd.pos] == '\n' || isd.str[isd.pos] == '\v' || \
			isd.str[isd.pos] == '\f' || isd.str[isd.pos] == '\r'))
			fatal_termination(memories, argc);
		isd.pos++;
	}
	return ((int)(isd.signum * number));
}

static void	check_leading_chars(t_input_string_data *isd, t_memories *memories, \
								int argc)
{
	char	*str;
	size_t	*pos;

	str = isd->str;
	pos = &(isd->pos);
	while (str[*pos] == ' ' || str[*pos] == '\t' || \
			str[*pos] == '\n' || str[*pos] == '\v' || \
			str[*pos] == '\f' || str[*pos] == '\r')
		(*pos)++;
	if (str[*pos] == '+' || str[*pos] == '-')
	{
		if (str[*pos] == '-')
			isd->signum = -1;
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

int	check_if_sorted(t_stack *stack_a)
{
	t_dl_node	*current_node;

	current_node = stack_a->head;
	while (current_node != NULL)
	{
		if (current_node->next != NULL)
		{
			if (current_node->value > current_node->next->value)
				return (0);
		}
		current_node = current_node->next;
	}
	return (1);
}
