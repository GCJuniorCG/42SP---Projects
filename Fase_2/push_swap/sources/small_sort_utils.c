/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:49:18 by gcamargo          #+#    #+#             */
/*   Updated: 2023/02/06 14:49:21 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_algoritmo(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	if (temp->num > temp->next->num
		&& temp->num < temp->next->next->num)
		return (1);
	else if (temp->next->num < temp->num
		&& temp->next->num > temp->next->next->num)
		return (2);
	else if (temp->next->next->num > temp->next->num
		&& temp->next->next->num < temp->num)
		return (3);
	else if (temp->next->next->num < temp->next->num
		&& temp->next->next->num > temp->num)
		return (4);
	else if (temp->num < temp->next->num
		&& temp->num > temp->next->next->num)
		return (5);
	return (0);
}

void	send_smallest(t_info *info)
{
	t_stack	*aux;
	int		smallest;
	int		count;
	int		decision;

	count = 1;
	smallest = MAX_INT;
	aux = info->stack_a;
	while (aux != NULL)
	{
		if (smallest > aux->num)
		{
			smallest = aux->num;
			count = smallest;
		}
		aux = aux->next;
		count++;
	}
	decision = rotate_or_reverse(info->size_b, smallest);
	to_b(info, smallest, decision);
}
