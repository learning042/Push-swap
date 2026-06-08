/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-v <tpinto-v@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 21:20:21 by tpinto-v          #+#    #+#             */
/*   Updated: 2026/04/19 17:10:21 by tpinto-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	if (lst == NULL)
		return (NULL);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}
/*
#include <stdio.h>
int	main(void)
{
	char	c[] = {'0', '1', '2'};
	t_list	*n[3];
	int	i = 0;
	while (i < 3)
	{
		n[i] = ft_lstnew(&c[i]);
		++i;
	}
	t_list	*head = n[0];
	ft_lstadd_front(&head, n[1]);
	ft_lstadd_front(&head, n[2]);
	for (t_list *tmp = head; tmp != NULL; tmp = tmp->next)
	{
		printf("%c->", *(char *)tmp->content);
	}
	printf("\n%c\n", *(char *)ft_lstlast(head)->content);
	for (t_list *tmp = head->next; tmp != NULL; tmp = tmp->next)
	{
		free(head);
		head = tmp;
	}
	free(head);
	return (0);
}
*/
