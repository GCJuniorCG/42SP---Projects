/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:49:46 by gcamargo          #+#    #+#             */
/*   Updated: 2023/02/06 14:49:47 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initializing_stack(t_info *info)
{
	ft_bzero(info, sizeof(t_info));
}

t_stack	*new_node(long int num)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->num = num;
	node->next = NULL;
	return (node);
}

void	ps_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last_element;

	last_element = ps_lstlast(*lst);
	if (last_element != NULL)
	{
		last_element->next = new;
		new->next = NULL;
	}
	else
	{
		*lst = new;
		new->next = NULL;
	}
}

void	bubble_sort(t_info *info)
{
	t_stack	*fix;
	t_stack	*aux;
	int		new_value;

	fix = info->temp;
	while (fix != NULL)
	{
		new_value = 0;
		aux = info->temp;
		while (aux != NULL)
		{
			if (fix->num > aux->num)
				new_value++;
			aux = aux->next;
		}
		ps_lstadd_back(&info->stack_a, new_node(new_value));
		fix = fix->next;
	}
}

int	order_check(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (temp->next != NULL)
	{
		if (temp->num > temp->next->num)
			return (0);
		temp = temp->next;
	}
	return (1);
}
