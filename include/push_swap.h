/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamas <atamas@stundent.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:08:44 by atamas            #+#    #+#             */
/*   Updated: 2024/03/15 15:52:36 by atamas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>

typedef struct s_stack
{
	int				number;
	struct	s_stack	*next;
}	t_stack;

void	free_stack(t_stack **head);
int		create_stack(t_stack **head, char **data);
void	print_stack(t_stack *stack);
int		memory_len(char **memory);
int		ft_atoi_check(char *str, int *error);
char	*free_the_memory(char **memory);
void	push_to_x(t_stack **from, t_stack **to, char *txt);
void	swap_x(t_stack **stack, char *txt);


#endif