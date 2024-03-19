/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamas <atamas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 01:10:49 by atamas            #+#    #+#             */
/*   Updated: 2024/03/19 17:17:34 by atamas           ###   ########.fr       */
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

/* 
Creates the stack from the memory
Returns 0 on error
*/
int	create_stack(t_stack **head, char **data)
{
	t_stack	*temp;
	t_stack	*last;
	int		error;

	temp = NULL;
	error = 0;
	while (*data)
	{
		temp = malloc(sizeof(t_stack));
		if (!temp || error == 1)
			return (free_stack(head), 0);
		temp->index = 0;
		temp->number = ft_atoi_check(*data++, &error);
		temp->next = NULL;
		if (*head)
			last->next = temp;
		else
			*head = temp;
		last = temp;
	}
	return (1);
}

void	print_stack(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	printf("{");
	while (temp)
	{
		printf(" |%d POS: %d| ", temp->number, temp->pos);
		temp = temp->next;
	}
	printf("}\n");
}

void	print_stack_b(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	printf("{");
	while (temp)
	{
		printf(" |%d T_POS: %d| ", temp->number, temp->target_pos);
		temp = temp->next;
	}
	printf("}\n");
}
