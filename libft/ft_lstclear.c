/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-v <tpinto-v@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 13:00:46 by tpinto-v          #+#    #+#             */
/*   Updated: 2026/04/18 13:38:26 by tpinto-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (lst == NULL)
		return ;
	tmp = *lst;
	while (tmp != NULL)
	{
		*lst = (*lst)->next;
		del(tmp->content);
		free(tmp);
		tmp = *lst;
	}
}
/*
#include <stdio.h>
int	main(void)
{
	t_list  *node0 = malloc(sizeof(t_list));
	t_list  *node1 = malloc(sizeof(t_list));
	t_list  *node2 = malloc(sizeof(t_list));
	t_list  **lst = &node0;
	node0->content = ft_strdup("42");
	node1->content = ft_strdup("...");
	node2->content = ft_strdup("hello");
	ft_lstadd_front(lst, node1);
	ft_lstadd_front(lst, node2);
	for (t_list *n = *lst; n != NULL; n = n->next)
		printf("address->%p %s ↓ \n", (void *)n, (char *)(n->content));
	ft_lstclear(lst, free);
}
*/
