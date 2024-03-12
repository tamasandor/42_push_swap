/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamas <atamas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 01:10:49 by atamas            #+#    #+#             */
/*   Updated: 2024/03/12 01:12:03 by atamas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../include/push_swap.h"

void	free_stack(t_stack **head)
{
	t_stack	*next;
	t_stack	*current;

	current = *head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

void	create_stack(t_stack **head, char **data)
{
	t_stack	*temp;
	t_stack	*last;

	temp = NULL;
	while (*data)
	{
		temp = malloc(sizeof(t_stack));
		if (!temp)
			free_stack(head);
		temp->number = atoi(*data++);
		temp->next = NULL;
		if (*head)
			last->next = temp;
		else
			*head = temp;
		last = temp;
	}
}

void	print_stack(t_stack *stack)
{
	printf("{");
	while (stack)
	{
		printf(" %d ", stack->number);
		stack = stack->next;
	}
	printf("}");
}
