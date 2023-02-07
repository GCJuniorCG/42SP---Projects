/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:49:59 by gcamargo          #+#    #+#             */
/*   Updated: 2023/02/06 14:50:00 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	organize_b(t_info *info)
{
	int		biggest;
	int		position;
	int		decision;

	while (info->size_b)
	{
		biggest = 0;
		position = find_biggest(&info->stack_b, &biggest);
		decision = rotate_or_reverse(info->size_b, position);
		to_a(info, biggest, decision);
	}
}

static int	find_position(t_info *info, int small_ref,
			int bigger_ref, int *number)
{
	t_stack	*temp;
	int		position;

	temp = info->stack_a;
	position = 0;
	while (temp != NULL)
	{
		if (temp->num >= small_ref && temp->num <= bigger_ref)
		{
			*number = temp->num;
			return (position);
		}
		position++;
		temp = temp->next;
	}
	return (-1);
}

static void	organize_a(t_info *info)
{
	int	i;
	int	number;
	int	decision;
	int	position;

	i = info->groups - 1;
	while (info->groups)
	{
		position = find_position(info, (info->group_size * i), (info->group_size
					* info->groups) - 1, &number);
		decision = rotate_or_reverse(info->size_a, position);
		to_b(info, number, decision);
		if (info->size_b == info->group_size)
		{
			i--;
			info->groups--;
			organize_b(info);
		}
	}
}

void	big_sort(t_info *info)
{
	if (info->size_a <= 100)
		info->group_size = 20;
	else if (info->size_a > 100
		&& info->size_a <= 250)
		info->group_size = 25;
	else if (info->size_a > 250
		&& info->size_a <= 500)
		info->group_size = 50;
	info->groups = (info->size_a / info->group_size);
	info->rest = info->size_a - (info->groups * info->group_size);
	if (info->rest)
		send_rest_to_b(info);
	organize_a(info);
}
