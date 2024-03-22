/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamas <atamas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:08:44 by atamas            #+#    #+#             */
/*   Updated: 2024/03/22 19:25:48 by atamas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int				index;
	int				number;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

void	free_stack(t_stack **head);
int		create_stack(t_stack **head, char **data);
void	print_stack(t_stack **stack);
int		memory_len(char **memory);
int		ft_atoi_check(char *str, int *error);
char	*free_the_memory(char **memory);
void	push_to_x(t_stack **from, t_stack **to, char *txt);
void	swap_x(t_stack **stack, char *txt);
void	rotate_x(t_stack **stack, char *txt);
void	reverse_rotate_x(t_stack **stack, char *txt);
void	multiple_operation(t_stack **stack_a, t_stack **stack_b, int op);
int		ft_parse(int argc, char *argv[], t_stack **stack_a);
void	current_pos(t_stack **stack_a, t_stack **stack_b);
void	target(t_stack **stack_a, t_stack **stack_b);
void	print_stack_b(t_stack **stack);
int		my_abs(int num);
void	cost(t_stack *stack_b, int size_a, int size_b);
int		do_cost_effective(t_stack **stack_a, t_stack **stack_b);
void	adjust_stack(t_stack **a, int len);
#endif