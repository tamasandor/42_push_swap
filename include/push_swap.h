/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamas <atamas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:08:44 by atamas            #+#    #+#             */
/*   Updated: 2024/03/12 01:14:29 by atamas           ###   ########.fr       */
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
void	create_stack(t_stack **head, char **data);
void	print_stack(t_stack *stack);

#endif