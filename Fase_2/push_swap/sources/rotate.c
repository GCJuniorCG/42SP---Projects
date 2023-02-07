/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:49:24 by gcamargo          #+#    #+#             */
/*   Updated: 2023/02/06 14:49:25 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack, int print)
{
	t_stack	*first;
	t_stack	*last;

	first = *stack;
	*stack = (*stack)->next;
	last = ps_lstlast(*stack);
	last->next = first;
	first->next = NULL;
	if (print == ra)
		ft_putstr("ra\n");
	if (print == rb)
		ft_putstr("rb\n");
}

void	rotate_r(t_info *info)
{
	rotate(&info->stack_a, ra);
	rotate(&info->stack_b, rb);
	ft_putstr("rr\n");
}
