/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamas <atamas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:23:11 by atamas            #+#    #+#             */
/*   Updated: 2024/03/06 20:39:12 by atamas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "../include/push_swap.h"
#include "../include/libft/libft.h"
#include "../testing.h"

int	ft_same(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	return (0);
}

int	ft_atoi_check(char *str, int *error)
{
	int			minus;
	long		res;

	res = 0;
	minus = 1;
	if (!str || !str[0])
		return (*error = 1, 0);
	if (ft_same("-2147483648", str))
		return (-2147483648);
	if (*str == '-')
	{
		str++;
		minus = -1;
	}
	while (*str && (*str >= '0' && *str <= '9') && *error == 0)
	{
		if ((minus == -1 && ((res * 10 + (*str - '0')) * -1) < INT_MIN)
			|| res * 10 + (*str - '0') > INT_MAX)
			return (*error = 1, 0);
		res = res * 10 + (*str++ - '0');
	}
	if (*str != '\0' || (res == 0 && minus == -1))
		*error = 1;
	return (res * minus);
}

int	error_free(int argc, char **memory)
{
	int	i;
	int	j;
	int	error;

	i = 0;
	error = 0;
	if (memory == NULL)
		error = 1;
	while (i < argc && error == 0)
	{
		ft_atoi_check(memory[i], &error);
		j = 0;
		while (j < i && error == 0)
		{
			if (ft_same(memory[i], memory[j]))
				error = 1;
			j++;
		}
		i++;
	}
	if (error == 1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

void	ft_parse(int argc, char *argv[], t_stack *stack_a, t_stack *stack_b)
{
	if (argc == 2)
	{
		if (argv[1][0] == '\0' || argv[1][0] == ' ')
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		argv = ft_split(argv[1], ' ');
		argc = memory_len(argv);
		if (error_free(argc, argv) == 0)
		{
			free_the_memory(argv);
			exit(1);
		}
	}
	else
	{
		if (error_free(--argc, ++argv) == 0)
			exit(1);
	}
	if (stack_a && stack_b)
	{}
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc >= 2)
		ft_parse(argc, argv, stack_a, stack_b);
	else
		return (0);
}
