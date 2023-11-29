/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniferr <viniferr@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:51:08 by viniferr          #+#    #+#             */
/*   Updated: 2023/11/05 15:51:46 by viniferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_split(char **arr, size_t j)
{
	while (j > 0)
	{
		free(arr[j]);
		j--;
	}
	free(arr);
}

static size_t	word_len(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static size_t	count_words(const char *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[j])
	{
		if (s[j] != c)
		{
			i++;
			while (s[j] && s[j] != c)
				j++;
		}
		else
			j++;
	}
	return (i);
}

static char	**words(char const *s, char c, char **arr)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	word;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			word = word_len(s + i, c);
			arr[j] = (char *)malloc((word + 1) * sizeof(char));
			if (!arr[j])
				free_split(arr, j);
			k = 0;
			while (k < word)
				arr[j][k++] = s[i++];
			arr[j++][word] = '\0';
		}
	}
	arr[j] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (0);
	arr = (char **)malloc((count_words(s, c) + 1) * sizeof(*arr));
	if (!arr)
		return (NULL);
	words(s, c, arr);
	return (arr);
}
