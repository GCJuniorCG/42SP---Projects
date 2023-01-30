/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:32:04 by gcamargo          #+#    #+#             */
/*   Updated: 2023/01/06 19:32:05 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpop(t_list **head)
{
	t_list	*last;
	t_list	*node;

	if (!head)
		return (NULL);
	node = *head;
	last = ft_lstlast(node);
	while (node->next->next)
		node = node->next;
	node->next = NULL;
	return (last);
}
