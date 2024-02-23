/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamas <atamas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:23:11 by atamas            #+#    #+#             */
/*   Updated: 2024/02/22 20:51:41 by atamas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void	ft_error(void)
{
	printf("Error\n"); // TODO: change it to ft_printf
	exit(0);
}

// atoi with checker
int	ft_atoi(char *str)
{
	int			minus;
	long int	res;

	res = 0;
	minus = 1;
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
	return ((int)(res * minus));
}

int	main(int argc, char *argv[])
{
	int	num = ft_atoi(argv[argc - 1]);
	printf("%d\n", num);
}