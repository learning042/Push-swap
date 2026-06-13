/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 17:04:58 by jlandeir          #+#    #+#             */
/*   Updated: 2026/06/01 12:14:21 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <unistd.h>

void	align_buffer(char *buffer);
int		has_newline(char *s);
char	*ft_gnl_strjoin(char *s1, char *s2);
void	start_buffer(int fd, char *buffer, ssize_t *nb_read);
char	*get_next_line(int fd);

#endif
