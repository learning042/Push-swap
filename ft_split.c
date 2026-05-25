/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 13:35:01 by jlandeir          #+#    #+#             */
/*   Updated: 2026/04/21 14:26:56 by jlandeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_words(const char *s, char c)
{
	size_t	i;
	size_t	wordcount;

	i = 0;
	wordcount = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			wordcount++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (wordcount);
}

static void	*ft_free_array(char **array, size_t len)
{
	while (len != 0)
	{
		len--;
		free(array[len]);
	}
	free(array);
	return (NULL);
}

static size_t	ft_word_length(const char *s, char c)
{
	size_t	word_len;

	word_len = 0;
	while (s[word_len] != '\0' && s[word_len] != c)
		word_len++;
	return (word_len);
}

char	**ft_split(const char *s, char c)
{
	size_t	wordcount;
	char	**word_array;
	size_t	word_len;

	wordcount = 0;
	word_array = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (word_array == NULL)
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		word_len = ft_word_length(s, c);
		if (*s)
		{
			word_array[wordcount] = ft_substr(s, 0, word_len);
			if (word_array[wordcount] == NULL)
				return (ft_free_array(word_array, wordcount));
			s += word_len;
			wordcount++;
		}
	}
	word_array[wordcount] = NULL;
	return (word_array);
}
