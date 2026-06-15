/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 12:56:54 by jlandeir          #+#    #+#             */
/*   Updated: 2026/06/01 12:35:29 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_gnl_strcat(char *s1, char *s2)
{
	while (*s1)
		s1++;
	while (s2 && *s2 && *s2 != '\n')
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	if (s2 && *s2 == '\n')
	{
		*s1 = *s2;
		*(s1 + 1) = '\0';
	}
	else
		*s1 = '\0';
	return ;
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*join;

	len_s1 = 0;
	while (s1 && s1[len_s1])
		len_s1++;
	len_s2 = 0;
	while (s2[len_s2] && (s2[len_s2] != '\n'))
		len_s2++;
	if (s2[len_s2] == '\n')
		len_s2++;
	join = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (join == NULL)
		return (free(s1), NULL);
	join[0] = '\0';
	ft_gnl_strcat(join, s1);
	ft_gnl_strcat(join, s2);
	free(s1);
	return (join);
}

int	has_newline(char *s)
{
	while (*s && *s != '\n')
		s++;
	return (*s == '\n');
}

void	align_buffer(char *buffer)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	while (buffer[i])
	{
		buffer[j] = buffer[i];
		i++;
		j++;
	}
	buffer[j] = '\0';
	return ;
}

void	start_buffer(int fd, char *buffer, ssize_t *nb_read)
{
	*nb_read = read(fd, buffer, BUFFER_SIZE);
	if (*nb_read < 0)
		return ;
	buffer[*nb_read] = '\0';
	return ;
}
