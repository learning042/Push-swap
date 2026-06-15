/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 14:10:15 by jlandeir          #+#    #+#             */
/*   Updated: 2026/06/15 13:58:58 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FPRINTF_H
# define FT_FPRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

int	ft_fprintf(int fd, const char *format, ...);
int	ft_putchar(int fd, unsigned char c);
int	ft_putstr(int fd, char *s);
int	ft_putnbr(int fd, int n);
int	ft_putptr(int fd, void *ptr);
int	ft_put_unsignedint(int fd, unsigned int n);
int	ft_put_hex_lower(int fd, unsigned int n);
int	ft_put_hex_upper(int fd, unsigned int n);

#endif
