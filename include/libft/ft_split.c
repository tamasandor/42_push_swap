/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test <test@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:24:18 by atamas            #+#    #+#             */
/*   Updated: 2024/02/29 04:21:59 by test             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
/* test begin
#include <stdio.h>
test end */

static char	*free_the_memory(char **memory)
{
	int	i;

	i = 0;
	while (memory[i] != NULL)
	{
		free(memory[i++]);
	}
	free(memory);
	return (NULL);
}

static int	word_counter(const char *string, char delimiter)
{
	int	amount_of_words;
	int	in_word;

	amount_of_words = 0;
	in_word = 0;
	while (*string)
	{
		if (*string != delimiter && in_word == 0)
			amount_of_words++;
		if (*string == delimiter)
			in_word = 0;
		else
			in_word = 1;
		string++;
	}
	return (amount_of_words);
}

static int	word_length(const char *string, char delimiter)
{
	int	length;
	int	i;

	length = 0;
	i = 0;
	while (string[i] != delimiter && string[i] != '\0')
	{
		length++;
		i++;
	}
	return (length);
}

char	**ft_split(char const *string, char delimiter, int *argc)
{
	char	**memory;
	int		mem_i;
	int		length;

	mem_i = 0;
	length = 0;
	*argc = word_counter(string, delimiter);
	memory = malloc(sizeof(char *) * (*argc + 1));
	if (!memory)
		return (NULL);
	while (*string != '\0')
	{
		if (*string != delimiter)
		{
			length = word_length(string, delimiter);
			memory[mem_i++] = ft_substr(string, 0, length);
			if (memory[mem_i - 1] == NULL)
				return ((void *)free_the_memory(memory));
			string += length;
		}
		else
			string++;
	}
	memory[mem_i] = NULL;
	return (memory);
}

/* 
int	main(void)
{
	int	i = 0;
	char	*string;
	char	**memory;

	string = "Andor is finishing Libft";
	memory = ft_split(string, ' ');
	while (memory[i])
	{
		printf("%s\n", memory[i]);
		i++;
	}
	free_the_memory(memory);
}
 */