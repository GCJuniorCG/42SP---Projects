/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:49:00 by gcamargo          #+#    #+#             */
/*   Updated: 2023/02/06 14:49:02 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack, int print)
{
	t_stack	*swap;
	t_stack	*third;

	if (!*stack || !(*stack)->next)
		return ;
	third = (*stack)->next->next;
	swap = *stack;
	*stack = (*stack)->next;
	(*stack)->next = swap;
	swap->next = third;
	if (print == sa)
		ft_putstr("sa\n");
	if (print == sb)
		ft_putstr("sb\n");
}

void	swap_s(t_info *stacks)
{
	swap(&stacks->stack_a, sa);
	swap(&stacks->stack_b, sb);
	ft_putstr("ss\n");
}
