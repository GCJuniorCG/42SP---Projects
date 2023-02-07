/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:50:03 by gcamargo          #+#    #+#             */
/*   Updated: 2023/02/06 14:50:05 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_biggest(t_stack **stack, int *biggest)
{
	t_stack	*temp;
	int		position;
	int		moves;

	temp = *stack;
	position = 0;
	moves = 0;
	while (temp != NULL)
	{
		if (*biggest < temp->num)
		{
			*biggest = temp->num;
			position = moves;
		}
		temp = temp->next;
		moves++;
	}
	return (position);
}

void	send_rest_to_b(t_info *info)
{
	int	number;
	int	position;
	int	decision;

	while (info->rest)
	{
		number = 0;
		position = find_biggest(&info->stack_a, &number);
		decision = rotate_or_reverse(info->size_a, position);
		to_b(info, number, decision);
		info->rest--;
	}
	organize_b(info);
}
