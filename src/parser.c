/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamas <atamas@stundent.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:23:11 by atamas            #+#    #+#             */
/*   Updated: 2024/03/05 19:27:08 by atamas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "../include/libft/libft.h"
#include "../testing.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

// TODO: Move it to folder include
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

// atoi with checker
int	ft_atoi_check(char *str) // add a pointer and change that
{
	int			minus;
	long		res;

	res = 0;
	minus = 1;
	if (ft_same("-2147483648", str))
		return (-2147483648);
	if (*str == '-')
	{
		str++;
		minus = -1;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		if ((minus == -1 && ((res * 10 + (*str - '0')) * -1) < INT_MIN)
			|| res * 10 + (*str - '0') > INT_MAX)
			ft_error();
		res = res * 10 + (*str++ - '0');
	}
	if (*str != '\0' || (res == 0 && minus == -1))
		ft_error();
	return (res * minus);
}

int	error_free(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (i < argc) // i < 3
	{
		ft_atoi_check(argv[i]);
		j = 0;
		while (j < i)
		{
			if (ft_same(argv[i], argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	if (argc <= 1)
		ft_error();
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = memory_len(argv);
		if (error_free(argc, argv) == 0 || argv == NULL)
			return (free_the_memory(argv), write(2, "Error\n", 6));
	}
	else if (argc > 2)
	{
		if (error_free(argc - 1, ++argv) == 0)
			return (write(2, "Error\n", 6));
		write(1, "NoError\n", 8);
	}
	printf("Argv: ");
	for (int i = 0; argv[i]; i++)
		printf("%s ", argv[i]);
	printf("\n");
}