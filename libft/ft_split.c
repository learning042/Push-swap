/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-v <tpinto-v@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 14:23:44 by tpinto-v          #+#    #+#             */
/*   Updated: 2026/04/19 21:48:23 by tpinto-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countwords(char const *str, char sep)
{
	size_t	word_count;

	word_count = 0;
	while (*str)
	{
		while (*str == sep)
			++str;
		if (*str)
		{
			++word_count;
			while (*str && *str != sep)
				++str;
		}
	}
	return (word_count);
}

static size_t	my_strlen(const char *s, char term)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0' && s[len] != term)
		len++;
	return (len);
}

static char	*my_strdup(const char *s, char term)
{
	int		i;
	char	*s_cpy;

	i = 0;
	s_cpy = (char *) malloc(my_strlen(s, term) + 1);
	if (s_cpy == NULL)
		return (NULL);
	while (s[i] != '\0' && s[i] != term)
	{
		s_cpy[i] = s[i];
		i++;
	}
	s_cpy[i] = '\0';
	return (s_cpy);
}

static void	ft_free_everything(char **arr, size_t size)
{
	while (size--)
		free(arr[size]);
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	size_t	word_count;

	word_count = 0;
	strings = malloc((ft_countwords(s, c) + 1) * sizeof(char *));
	if (strings == NULL)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			++s;
		if (!*s)
			break ;
		strings[word_count] = my_strdup(s, c);
		if (strings[word_count] == NULL)
			return (ft_free_everything(strings, word_count), NULL);
		++word_count;
		s += my_strlen(s, c);
	}
	strings[word_count] = NULL;
	return (strings);
}
/*
#include <stdio.h>
int	main(void)
{
	char		**array = ft_split("aaa,,bbb", ',');
	int			i = 0;
	while (array[i] != NULL)
	{
		printf("%s\n", array[i]);
		free(array[i]);
		++i;
	}
	free(array);
	char	*str = NULL;
	char	**array2 = ft_split(str, ',');
}
*/
