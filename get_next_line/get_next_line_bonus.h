/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 17:04:58 by jlandeir          #+#    #+#             */
/*   Updated: 2026/06/01 13:06:42 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef FD_MAX
#  define FD_MAX 1023
# endif

# include <stdlib.h>
# include <unistd.h>

void	align_buffer(char *buffer);
char	*get_next_line(int fd);
int		has_newline(char *s);
char	*ft_gnl_strjoin(char *s1, char *s2);
void	start_buffer(int fd, char *buffer, ssize_t *nb_read);

#endif
