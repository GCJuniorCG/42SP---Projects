/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:32:39 by gcamargo          #+#    #+#             */
/*   Updated: 2023/01/06 19:32:40 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdel(t_list **head)
{
	t_list	*node;

	if (!head)
		return (NULL);
	node = *head;
	*head = node->next;
	node->next = NULL;
	return (node);
}
