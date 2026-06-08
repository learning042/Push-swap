/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-v <tpinto-v@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 23:13:45 by tpinto-v          #+#    #+#             */
/*   Updated: 2026/04/18 12:58:28 by tpinto-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL)
		return ;
	if (del != NULL)
		del(lst->content);
	free(lst);
}
/*
#include <stdio.h>
int	main(void)
{
	t_list	*n = malloc(sizeof(t_list));
	n->content = ft_strdup("hello");
	n->next = NULL;
	printf("%s\n", n->content);
	ft_lstdelone(n, free);
	n = NULL;
}
*/
