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
// check for the bigger number than integer
// in this case the program should exit

void ft_error(void)
{
	printf("Error\n"); // TODO: change it to ft_printf
	exit(0);
}

// atoi with checker
int	ft_atoi(char *str)
{
	int	num;
	int	minus;

	num = 0;
	minus = 1;
	if (*str == '-')
	{
		str++;
		minus = -1;
	}
	while(*str && (*str >= '0' && *str <= '9'))
	{
		// TODO: Overflow protection
			// if ((num * 10 / 2147483647 + (*str - '0')) > 0 && minus == 1)
			// 	ft_error();
			// else if (((num * 10 + (*str - '0')) / 2147483648) >= 1 && minus == -1)
			// 	ft_error();
			num = num * 10 + (*str++ - '0');
	}
	if (*str != '\0')
		ft_error();
	return (num * minus);
}

int	main(int argc, char *argv[])
{
	int	num = ft_atoi(argv[argc - 1]);
	printf("%d\n", num);
}