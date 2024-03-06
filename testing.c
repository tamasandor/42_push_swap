#include <stdlib.h>
#include <stdio.h>

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