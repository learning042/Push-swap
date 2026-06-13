/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 17:04:04 by jlandeir          #+#    #+#             */
/*   Updated: 2026/06/06 12:51:07 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FD_MAX + 1][BUFFER_SIZE + 1];
	char		*line;
	ssize_t		nb_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || FD_MAX < 0 || fd > FD_MAX)
		return (NULL);
	line = NULL;
	nb_read = 1;
	while (1)
	{
		if (buffer[fd][0] == '\0')
			start_buffer(fd, buffer[fd], &nb_read);
		if (nb_read < 0)
			return (free(line), NULL);
		if (nb_read == 0)
			return (line);
		line = ft_gnl_strjoin(line, buffer[fd]);
		if (line == NULL)
			return (NULL);
		if (has_newline(buffer[fd]))
			return (align_buffer(buffer[fd]), line);
		else
			align_buffer(buffer[fd]);
	}
}
