/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:49:06 by gcamargo          #+#    #+#             */
/*   Updated: 2023/02/06 14:49:08 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_or_reverse(int size, int position)
{
	int	half;

	half = size / 2;
	if (half <= position)
		return (1);
	else if (half > position)
		return (2);
	return (0);
}

void	to_b(t_info *info, int num, int decision)
{
	while (info->stack_a->num != num)
	{
		if (decision == 1)
			reverse_rotate(&info->stack_a, rra);
		if (decision == 2)
			rotate(&info->stack_a, ra);
	}
	push_a_to_b(info);
}

void	to_a(t_info *info, int num, int decision)
{
	while (info->stack_b->num != num)
	{
		if (decision == 1)
			reverse_rotate(&info->stack_b, rrb);
		if (decision == 2)
			rotate(&info->stack_b, rb);
	}
	push_b_to_a(info);
}
