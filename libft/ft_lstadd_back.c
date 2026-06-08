/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-v <tpinto-v@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 22:36:10 by tpinto-v          #+#    #+#             */
/*   Updated: 2026/04/19 16:37:17 by tpinto-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}
/*
#include <stdio.h>
int	main(void)
{
	char	c[] = {'0', '1', '2'};
	t_list	*n[4];
	int	i = 0;
	while (i < 3)
	{
		n[i] = ft_lstnew(&c[i]);
		++i;
	}
	t_list	*head = n[0];
	ft_lstadd_back(&head, n[1]);
	ft_lstadd_back(&head, n[2]);
	for (t_list *tmp = head; tmp != NULL; tmp = tmp->next)
	{
		printf("%c->", *(char *)tmp->content);
	}
	printf("\n");
	free(n[0]);
	free(n[1]);
	free(n[2]);
}
*/
