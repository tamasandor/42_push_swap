/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamas <atamas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:23:11 by atamas            #+#    #+#             */
/*   Updated: 2024/02/24 21:26:08 by atamas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void	ft_error(void)
{
	printf("Error\n"); // TODO: change it to ft_printf
	exit(1);
}

void	ft_error1(void)
{
	printf("Error1\n"); // TODO: change it to ft_printf
	exit(1);
}

// TODO: Move it to folder include
int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (1);
		s1++;
		s2++;
	}
	if (*s1 == '\0' && *s2 == '\0')
		return (0);
	return (1);
}

// atoi with checker
int	ft_atoi(char *str)
{
	int			minus;
	long		res;

	res = 0;
	minus = 1;
	if (!ft_strcmp("-2147483648", str))
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
	if (*str != '\0')
		ft_error();
	return (res * minus);
}

/* int	error_free(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (i <= argc)
	{
		ft_atoi(argv[i]);
		j = 1;
		while (j < i)
		{
			j++;
			printf("%s - %s\n", argv[i], argv[j]);
			if (!ft_strcmp(argv[i], argv[j]))
				ft_error1();
		}
		i++;
		// check until the i position if something is the same as this
		// than its an error, call ft_error
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	if (argc <= 1)
		ft_error();
	else if (argc == 2)
	{
		// TODO: ft_split
		// ft_split();
	}
	else if (error_free(argc, argv))
	{
		printf("NO ERROR");
	}
	int	num = ft_atoi(argv[argc - 1]);
	printf("%d\n", num);
} */