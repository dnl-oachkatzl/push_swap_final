/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:27:00 by daspring          #+#    #+#             */
/*   Updated: 2024/06/15 15:29:05 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_argv_as_words(char ***argv_as_words, int argc)
{
	int	pos;

	while (argc > 1)
	{
		pos = 0;
		while (argv_as_words[argc - 2][pos])
		{
			free(argv_as_words[argc - 2][pos]);
			pos++;
		}
		free(argv_as_words[argc - 2]);
		argc--;
	}
	free(argv_as_words);
}
