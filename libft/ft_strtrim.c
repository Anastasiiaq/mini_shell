/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhizdahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 16:22:35 by jhizdahr          #+#    #+#             */
/*   Updated: 2021/04/24 15:48:41 by jhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	find_start(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	counter;

	counter = 0;
	i = 0;
	while (i < ft_strlen(s1))
	{
		j = 0;
		while (j < ft_strlen(set))
		{
			if (s1[i] == set[j])
			{
				counter++;
				break ;
			}
			if (j == (ft_strlen(set) - 1))
				return (i);
			j++;
		}
		i++;
	}
	if (counter == ft_strlen(s1))
		return (ft_strlen(s1) - 1);
	return (0);
}

static size_t	find_end(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(s1) - 1;
	while (i > find_start(s1, set))
	{
		j = 0;
		while (j < ft_strlen(set))
		{
			if (s1[i] == set[j])
				break ;
			if (j == (ft_strlen(set) - 1))
				return (i);
			j++;
		}
		i--;
	}
	return (i);
}

static int	check_s1_consist_of_only_setsymbols(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < ft_strlen(s1))
	{
		j = 0;
		while (j < ft_strlen(set))
		{
			if (s1[i] == set[j])
				break ;
			if (j == (ft_strlen(set) - 1))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	char	*result;
	size_t	start;
	size_t	end;

	if (s1 == NULL)
		return (NULL);
	start = find_start(s1, set);
	end = find_end(s1, set);
	result = malloc((end - start + 1) * sizeof(char) + 1);
	if (check_s1_consist_of_only_setsymbols(s1, set))
	{
		result[0] = '\0';
		return (result);
	}
	if (result == NULL)
		return (NULL);
	i = start;
	while (i <= end)
	{
		result[i - start] = s1[i];
		i++;
	}
	result[i - start] = '\0';
	return (result);
}
