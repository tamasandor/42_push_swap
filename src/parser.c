/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamas <atamas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:23:11 by atamas            #+#    #+#             */
/*   Updated: 2024/03/26 18:07:11 by atamas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include "../include/push_swap.h"
#include "../include/libft/libft.h"

static char	*trim_zero(char *string)
{
	if (*string == '+' || *string == '-')
		string++;
	while (*string == '0')
	{
		string++;
	}
	return (string);
}

static int	ft_same(char *s1, char *s2)
{
	int	s1minus;
	int	s2minus;

	s1minus = 0;
	s2minus = 0;
	if (*s1 == '-')
		s1minus = 1;
	s1 = trim_zero(s1);
	if (*s2 == '-')
		s2minus = 1;
	s2 = trim_zero(s2);
	if (s1minus != s2minus)
		return (0);
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
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
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

static int	error_free(int argc, char **memory)
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
		return (write(2, "Error\n", 6), 0);
	return (1);
}

int	ft_parse(int argc, char *argv[], t_stack **stack_a)
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
		if (!error_free(argc, argv) || !create_stack(stack_a, argv))
		{
			free_the_memory(argv);
			exit(1);
		}
		free_the_memory(argv);
	}
	else
	{
		if (!error_free(--argc, ++argv) || !create_stack(stack_a, argv))
			exit(1);
	}
	return (argc);
}
