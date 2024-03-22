/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effective_adjust.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamas <atamas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 23:01:03 by atamas            #+#    #+#             */
/*   Updated: 2024/03/22 19:24:07 by atamas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <limits.h>

static int	lowest_pos(t_stack **a)
{
	int		lowest_position;
	int		lowest_index;
	t_stack	*temp;

	temp = *a;
	lowest_position = temp->pos;
	lowest_index = INT_MAX;
	while (temp)
	{
		if (temp->index < lowest_index)
		{
			lowest_index = temp->index;
			lowest_position = temp->pos;
		}
		temp = temp->next;
	}
	return (lowest_position);
}

void	adjust_stack(t_stack **a, int len)
{
	int	low_position;

	current_pos(a, a);
	low_position = lowest_pos(a);
	if (low_position > len / 2)
	{
		while (low_position < len)
		{
			low_position++;
			reverse_rotate_x(a, "rra\n");
		}
	}
	else
	{
		while (low_position > 0)
		{
			low_position--;
			rotate_x(a, "ra\n");
		}
	}
}

static void	same_moves(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		multiple_operation(a, b, 2);
		(*cost_a)--;
		(*cost_b)--;
	}
	while (*cost_a < 0 && *cost_b < 0)
	{
		multiple_operation(a, b, 3);
		(*cost_a)++;
		(*cost_b)++;
	}
}

void	do_move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	same_moves(a, b, &cost_a, &cost_b);
	while (cost_a > 0)
	{
		rotate_x(a, "ra\n");
		cost_a--;
	}
	while (cost_a < 0)
	{
		reverse_rotate_x(a, "rra\n");
		cost_a++;
	}
	while (cost_b > 0)
	{
		rotate_x(b, "rb\n");
		cost_b--;
	}
	while (cost_b < 0)
	{
		reverse_rotate_x(b, "rrb\n");
		cost_b++;
	}
	push_to_x(b, a, "pa\n");
}

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
