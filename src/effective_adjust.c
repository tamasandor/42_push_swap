/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effective_adjust.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamas <atamas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 23:01:03 by atamas            #+#    #+#             */
/*   Updated: 2024/03/22 16:05:07 by atamas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <limits.h>

int	do_cost_effective(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	temp = *stack_b;
	cheapest = INT_MAX;
	while (temp)
	{
		if (my_abs(temp->cost_a) + my_abs(temp->cost_b) < cheapest)
		{
			cheapest = my_abs(cost_a) + my_abs(cost_b);
			cost_a = temp->cost_a;
			cost_b = temp->cost_b;
		}
		temp = temp->next;
	}
	do_move(stack_a, stack_b, cost_a, cost_b);
	return (1);
}
