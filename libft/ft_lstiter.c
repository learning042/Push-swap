/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-v <tpinto-v@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 13:39:14 by tpinto-v          #+#    #+#             */
/*   Updated: 2026/04/19 17:11:58 by tpinto-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;

	if (lst == NULL || f == NULL)
		return ;
	tmp = lst;
	while (tmp != NULL)
	{
		f(tmp->content);
		tmp = tmp->next;
	}
}
/*
void	ft_test(void *c)
{
	*(char *)c += 1;
}

#include <stdio.h>
int	main(void)
{
	char	c[] = {'0', '1', '2'};
	t_list	*node0 = ft_lstnew(&c[0]);
	t_list	*node1 = ft_lstnew(&c[1]);
	t_list	*node2 = ft_lstnew(&c[2]);
	t_list	*lst = node0;
	ft_lstadd_back(&lst, node1);
	ft_lstadd_back(&lst, node2);
	for (t_list *tmp = lst; tmp != NULL; tmp = tmp->next)
		printf("Address: %p, *Content: %c ↓\n", tmp, *(char *)tmp->content);
	ft_lstiter(lst, ft_test);
	printf("-------------------------------------------------------------\n");
	for (t_list *tmp = lst; tmp != NULL; tmp = tmp->next)
		printf("Address: %p, *Content: %c ↓\n", tmp, *(char *)tmp->content);
}
*/
