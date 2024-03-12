/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamas <atamas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:49:22 by atamas            #+#    #+#             */
/*   Updated: 2024/03/07 16:49:29 by atamas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*free_the_memory(char **memory)
{
	int	i;

	i = 0;
	while (memory[i])
	{
		free(memory[i]);
		i++;
	}
	free(memory);
	return (NULL);
}

int	memory_len(char **memory)
{
	int	i;

	i = 0;
	if (!memory)
		return (0);
	while (memory[i])
		i++;
	return (i);
}
