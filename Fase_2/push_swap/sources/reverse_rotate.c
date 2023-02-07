/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:49:29 by gcamargo          #+#    #+#             */
/*   Updated: 2023/02/06 14:49:31 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ps_lstlast(t_stack *lst)
{
	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

void	del_last(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last_node;

	temp = *stack;
	while (temp->next->next != NULL)
		temp = temp->next;
	last_node = temp->next;
	if (temp->next)
		temp->next = NULL;
	free(last_node);
}

//último número vai para o topo da própria lista
void	reverse_rotate(t_stack **stack, int print)
{
	t_stack	*last;
	t_stack	*first;
	t_stack	*pen;

	last = ps_lstlast(*stack);
	first = *stack;
	pen = *stack;
	while (pen->next->next != NULL)
		pen = pen->next;
	pen->next = NULL;
	last->next = first;
	*stack = last;
	if (print == rra)
		ft_putstr("rra\n");
	if (print == rrb)
		ft_putstr("rrb\n");
}

void	reverse_rotate_r(t_info *info)
{
	reverse_rotate(&info->stack_a, rra);
	reverse_rotate(&info->stack_b, rrb);
	ft_putstr("rrr\n");
}
