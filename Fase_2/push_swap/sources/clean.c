/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:49:50 by gcamargo          #+#    #+#             */
/*   Updated: 2023/02/06 14:49:51 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_double(t_stack **stack, long int num)
{
	t_stack	*temp;
	int		times;

	temp = *stack;
	times = 0;
	if (num > MAX_INT || num < MIN_INT)
		return (0);
	while (temp)
	{
		if (temp->num == num)
			times++;
		if (times == 2)
			return (0);
		temp = temp->next;
	}
	temp = NULL;
	return (1);
}

void	freelist(t_stack *stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	while (stack != NULL)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}

void	freeall(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}
