/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-v <tpinto-v@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 15:33:00 by tpinto-v          #+#    #+#             */
/*   Updated: 2026/04/17 19:13:13 by tpinto-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}
/*
int main(void)
{

	char    c[3] = {'0', '1', '2'};

	t_list  *node0 = ft_lstnew(&c[0]);
	t_list  *node1 = ft_lstnew(&c[1]);
	t_list  *node2 = ft_lstnew(&c[2]);
	t_list  *lst = node0;
	ft_lstadd_front(&lst, node1);
	ft_lstadd_front(&lst, node2);
	for (t_list *n = lst; n != NULL; n = n->next)
		printf("address->%p %c ↓ \n", (void *)n, *(char *)(n->content));
	
	free(node0);
	free(node1);
	free(node2);
	return (0);
}
*/
