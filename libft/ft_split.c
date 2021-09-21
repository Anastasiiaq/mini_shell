/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhizdahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:43:58 by jhizdahr          #+#    #+#             */
/*   Updated: 2021/04/25 19:36:15 by jhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	words_counter(char const *s, char c)
{
	size_t	counter;
	size_t	i;

	i = 0;
	if (s[0] == '\0')
		return (0);
	if (s[0] == c)
		counter = 0;
	else
		counter = 1;
	while (i < (ft_strlen(s) - 1))
	{
		if (s[i] == c && s[i + 1] != c)
			counter++;
		i++;
	}
	return (counter);
}

static void	array_of_borders_help(char const *s, char c, int j, int *result)
{
	size_t	i;

	i = 1;
	while (i < ft_strlen(s))
	{
		if (s[i - 1] == c && s[i] != c)
		{
			result[j] = i;
			j++;
		}
		if (s[i] != c && s[i + 1] == c)
		{
			result[j] = i;
			j++;
		}
		i++;
	}
	if (s[ft_strlen(s) - 1] != c)
		result[j] = ft_strlen(s) - 1;
}

static int	*making_array_of_borders(char const *s, char c, int words)
{
	int	*result;
	int	j;

	result = malloc(words * 2 * sizeof(int));
	if (result == NULL)
		return (NULL);
	if (words != 0)
	{
		j = 0;
		if (s[0] != c)
		{
			result[0] = 0;
			j++;
		}
		if (s[0] != c && s[1] == c)
		{
			result[j] = 0;
			j++;
		}
		array_of_borders_help(s, c, j, result);
	}
	return (result);
}

static void	free_array(char **result, size_t i, int *b)
{
	while (i >= 0)
	{
		free (result[i]);
		i--;
	}
	free (b);
	free (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;
	int		*b;
	size_t	words;

	words = words_counter(s, c);
	result = (char **)malloc((words + 1) * sizeof(char *));
	b = making_array_of_borders(s, c, words);
	if (b == NULL || result == NULL)
		return (NULL);
	i = 0;
	while (i < words)
	{
		result[i] = ft_substr(s, b[2 * i], b[2 * i + 1] - b[2 * i] + 1);
		if (result[i] == NULL)
		{
			free_array(result, i, b);
			return (NULL);
		}
		i++;
	}
	free (b);
	result[i] = NULL;
	return (result);
}
