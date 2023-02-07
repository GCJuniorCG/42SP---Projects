/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:49:12 by gcamargo          #+#    #+#             */
/*   Updated: 2023/02/06 14:49:14 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_elements(t_info *info)
{
	if (info->stack_a->num > info->stack_a->next->num)
		swap(&info->stack_a, sa);
}

void	three_elements(t_stack **stack)
{
	int	algoritmo;

	algoritmo = find_algoritmo(stack);
	if (algoritmo == 1)
		swap(stack, sa);
	if (algoritmo == 2)
	{
		swap(stack, sa);
		reverse_rotate(stack, rra);
	}
	if (algoritmo == 3)
		rotate(stack, ra);
	if (algoritmo == 4)
	{
		swap(stack, sa);
		rotate(stack, ra);
	}
	if (algoritmo == 5)
		reverse_rotate(stack, rra);
}

void	four_elements(t_info *info)
{
	send_smallest(info);
	three_elements(&info->stack_a);
	push_b_to_a(info);
}

void	five_elements(t_info *info)
{
	send_smallest(info);
	send_smallest(info);
	three_elements(&info->stack_a);
	push_b_to_a(info);
	push_b_to_a(info);
}

void	small_sort(t_info *info)
{
	if (info->size_a == 2)
		two_elements(info);
	else if (info->size_a == 3)
		three_elements(&info->stack_a);
	else if (info->size_a == 4)
		four_elements(info);
	else if (info->size_a == 5)
		five_elements(info);
}
