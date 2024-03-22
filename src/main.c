/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamas <atamas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:52:50 by atamas            #+#    #+#             */
/*   Updated: 2024/03/22 19:25:54 by atamas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <unistd.h>

static void	assign_index(t_stack *stack_a, int len)
{
	int		index;
	t_stack	*lowest;
	t_stack	*current;

	index = 1;
	while (index <= len)
	{
		current = stack_a;
		lowest = NULL;
		while (current)
		{
			if (current->index == 0)
				if (!lowest || current->number < lowest->number)
					lowest = current;
			current = current->next;
		}
		if (lowest)
			lowest->index = index++;
	}
}

static int	is_sorted(t_stack *stack_a)
{
	t_stack	*current;

	current = stack_a;
	while (current->next)
	{
		if (current->number > current->next->number)
			return (0);
		current = current->next;
	}
	return (1);
}

static void	sort_three(t_stack **stack_a)
{
	if ((*stack_a)->index > (*stack_a)->next->index
		&& (*stack_a)->index > (*stack_a)->next->next->index)
		rotate_x(stack_a, "ra\n");
	else if ((*stack_a)->next->index > (*stack_a)->index)
		reverse_rotate_x(stack_a, "rra\n");
	if ((*stack_a)->index > (*stack_a)->next->index)
		swap_x(stack_a, "sa\n");
}

static void	sort_more(t_stack **stack_a, t_stack **stack_b, int len)
{
	t_stack	*temp_b;
	int		len_b;

	len_b = 0;
	temp_b = *stack_b;
	while (len_b < len - 3)
	{
		len_b++;
		push_to_x(stack_a, stack_b, "pb\n");
	}
	if (!is_sorted(*stack_a))
		sort_three(stack_a);
	while (*stack_b)
	{
		target(stack_a, stack_b);
		cost(*stack_b, len - len_b, len_b);
		len_b -= do_cost_effective(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		adjust_stack(stack_a, len);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc >= 2)
		argc = ft_parse(argc, argv, &stack_a);
	else
		return (0);
	assign_index(stack_a, argc);
	if (argc == 2 && !is_sorted(stack_a))
		swap_x(&stack_a, "sa\n");
	else if (argc == 3 && !is_sorted(stack_a))
		sort_three(&stack_a);
	else if (argc > 3 && !is_sorted(stack_a))
		sort_more(&stack_a, &stack_b, argc);
	free_stack(&stack_a);
	free_stack(&stack_b);
}
