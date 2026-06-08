/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-v <tpinto-v@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 15:29:58 by tpinto-v          #+#    #+#             */
/*   Updated: 2026/04/27 17:33:53 by tpinto-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define DECBASE "0123456789"
# define HEXBASEUPP "0123456789ABCDEF"
# define HEXBASELOW "0123456789abcdef"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

void	ft_putnbr_base(unsigned long n, char *base, size_t lbase, int *count);
void	ft_putchar(char c, int *count);
void	ft_putstr(char *s, int *count);
void	ft_putuns(unsigned long n, char *base, int *count);
void	ft_putsign(long n, char *base, int *count);
void	ft_putptr(unsigned long n, int *count);
int		ft_printf(const char *s, ...);
#endif
