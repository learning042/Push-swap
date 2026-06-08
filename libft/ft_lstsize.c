/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-v <tpinto-v@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 18:09:02 by tpinto-v          #+#    #+#             */
/*   Updated: 2026/04/17 21:17:58 by tpinto-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*tmp;
	int		len;

	len = 0;
	tmp = lst;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		++len;
	}
	return (len);
}
/*
#include <stdio.h>
int	main(void)
{
	char	c[] = {'0', '1', '2'};
	t_list	*n0 = ft_lstnew(&c[0]);
	t_list	*n1 = ft_lstnew(&c[1]);
	t_list	*n2 = ft_lstnew(&c[2]);
	t_list	*head = n0;
	ft_lstadd_front(&head, n1);
	ft_lstadd_front(&head, n2);
	printf("%i\n", ft_lstsize(head));
	free(n0);
	free(n1);
	free(n2);
	return (0);
}
*/
