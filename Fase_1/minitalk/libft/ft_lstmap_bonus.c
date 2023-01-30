/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:24:55 by gcamargo          #+#    #+#             */
/*   Updated: 2022/10/04 17:24:55 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*new_list;

	if (lst == NULL || f == NULL)
		return (NULL);
	new_list = (t_list *)malloc(sizeof(t_list));
	if (new_list == NULL)
		return (NULL);
	tmp = new_list;
	tmp->content = (int *)f(lst->content);
	lst = lst->next;
	while (lst != NULL)
	{
		tmp->next = (t_list *)malloc(sizeof(t_list));
		tmp = tmp->next;
		if (tmp == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		tmp->content = (int *)f(lst->content);
		lst = lst->next;
	}
	tmp->next = NULL;
	return (new_list);
}
