/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-v <tpinto-v@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 12:43:40 by tpinto-v          #+#    #+#             */
/*   Updated: 2026/04/19 21:45:23 by tpinto-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*newlst;
	void	*map;

	if (lst == NULL)
		return (NULL);
	new = NULL;
	newlst = NULL;
	map = NULL;
	while (lst != NULL)
	{
		map = f(lst->content);
		if (map == NULL)
			return (ft_lstclear(&newlst, del), NULL);
		new = ft_lstnew(map);
		if (new == NULL)
			return (ft_lstclear(&newlst, del), NULL);
		ft_lstadd_back(&newlst, new);
		lst = lst->next;
	}
	return (newlst);
}
/*
void *ft_test1(void *c)
{
    *(char *)c += 1;
    return (NULL);
}

void *ft_test2(void *c)
{
    char *new = malloc(sizeof(char));
    if (!new)
        return (NULL);
    *new = *(char *)c + 1;
    return (new);
}


#include <stdio.h>
int	main(void)
{
	t_list	*n[3];
	int i = 0;
	while (i < 3)
	{
   		char *c = malloc(sizeof(char));
    	*c = '0' + i;
    	n[i] = ft_lstnew(c);
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
	t_list	*newlst = ft_lstmap(head, ft_test2, free);
	for (t_list *tmp = newlst; tmp != NULL; tmp = tmp->next)
	{
		printf("%c->", *(char *)tmp->content);
	}
	ft_lstclear(&head, free);
	ft_lstclear(&newlst, free);
}
*/
