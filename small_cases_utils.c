/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_cases_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:57:18 by daspring          #+#    #+#             */
/*   Updated: 2024/06/20 19:00:39 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index_of_zero(t_input *input)
{
	int	pos;

	pos = 0;
	while (pos < input->num_of_entries)
	{
		if (input->sorted_input[pos] == 0)
			return (pos);
		pos++;
	}
	return (-1);
}

void	array_del_entry(int *array, int idx_entry, int len)
{
	while (idx_entry < len - 1)
	{
		array[idx_entry] = array[idx_entry + 1];
		idx_entry++;
	}
}

void	ra_for_array(int *array, int len)
{
	int	tmp;

	tmp = array[0];
	array_del_entry(array, 0, len);
	array[len - 1] = tmp;
}

void	array_decrement_by_one(int *array, int len)
{
	int	pos;

	pos = 0;
	while (pos < len)
	{
		array[pos]--;
		pos++;
	}
}
