/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 17:04:04 by jlandeir          #+#    #+#             */
/*   Updated: 2026/06/01 12:11:33 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		nb_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	nb_read = 1;
	while (1)
	{
		if (buffer[0] == '\0')
			start_buffer(fd, buffer, &nb_read);
		if (nb_read < 0)
			return (free(line), NULL);
		if (nb_read == 0)
			return (line);
		line = ft_gnl_strjoin(line, buffer);
		if (line == NULL)
			return (NULL);
		if (has_newline(buffer))
			return (align_buffer(buffer), line);
		else
			align_buffer(buffer);
	}
}
