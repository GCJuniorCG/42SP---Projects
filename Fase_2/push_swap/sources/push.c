/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:49:34 by gcamargo          #+#    #+#             */
/*   Updated: 2023/02/06 14:49:35 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del_first_node(t_stack **stack)
{
	t_stack	*temp;

	if ((*stack)->next == NULL)
		free((*stack));
	else
	{
		temp = *stack;
		(*stack) = (*stack)->next;
		free(temp);
		temp = NULL;
	}
}

void	push_a_to_b(t_info *info)
{
	t_stack	*first_a;
	t_stack	*first_b;

	first_a = info->stack_a;
	info->stack_a = info->stack_a->next;
	first_b = info->stack_b;
	info->stack_b = first_a;
	first_a->next = first_b;
	info->size_a--;
	info->size_b++;
	ft_putstr("pb\n");
}

void	push_b_to_a(t_info *info)
{
	t_stack	*first_b;
	t_stack	*first_a;

	first_b = info->stack_b;
	info->stack_b = info->stack_b->next;
	first_a = info->stack_a;
	info->stack_a = first_b;
	first_b->next = first_a;
	info->size_a++;
	info->size_b--;
	ft_putstr("pa\n");
}
