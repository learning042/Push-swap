/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:56:55 by jlandeir          #+#    #+#             */
/*   Updated: 2026/04/22 18:36:18 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*f_lst;
	t_list	*curr_node;

	f_lst = NULL;
	while (lst != NULL)
	{
		curr_node = ft_lstnew(f(lst->content));
		if (curr_node == NULL)
		{
			ft_lstclear(&f_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&f_lst, curr_node);
		lst = lst->next;
	}
	return (f_lst);
}
