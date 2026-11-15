/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazorin <mazorin@student.42barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 23:34:43 by mazorin           #+#    #+#             */
/*   Updated: 2026/11/15 12:07:08 by mazorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	countwords(char const *s, char c)
{
	size_t	words;

	words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			words++;
		while (*s && *s != c)
			s++;
	}
	return (words);
}

static void	free_split(char **result, size_t n)
{
	while (n--)
		free(result[n]);
	free(result);
}

static char	**add_words(char **result, char const *s, char c, size_t words)
{
	unsigned int	i;
	size_t			wordlen;

	i = 0;
	while (i < words)
	{
		while (*s == c)
			s++;
		wordlen = 0;
		while (s[wordlen] && s[wordlen] != c)
			wordlen++;
		result[i] = ft_substr(s, 0, wordlen);
		if (result[i] == NULL)
		{
			free_split (result, i);
			return (NULL);
		}
		i++;
		s = s + wordlen;
	}
	result[i] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	words;

	if (s == NULL)
		return (NULL);
	words = countwords(s, c);
	split = malloc(sizeof(char *) * (words + 1));
	if (split == NULL)
		return (NULL);
	split = add_words(split, s, c, words);
	return (split);
}
