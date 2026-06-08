/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-v <tpinto-v@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 13:41:22 by tpinto-v          #+#    #+#             */
/*   Updated: 2026/04/17 14:22:54 by tpinto-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *) malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
/*
#include <stdio.h>
int	main(void)
{
	char	c[3] = {'0', '1', '2'};
	t_list	*lst = ft_lstnew(&c[0]);
	t_list	*node1 = ft_lstnew(&c[1]);
	t_list	*node2 = ft_lstnew(&c[2]);
	lst->next = node1;
	node1->next = node2;
	t_list	*node;
	for (node = lst; node != NULL; node = node->next)
	{

		printf("%c ->", *(char *)(node->content));
		//printf("%p ->", node);
	}
	//printf("%p", node);
	free(lst);
	free(node1);
	free(node2);
}
*/
