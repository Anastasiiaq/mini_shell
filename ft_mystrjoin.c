/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mystrjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhizdahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:29:30 by jhizdahr          #+#    #+#             */
/*   Updated: 2021/09/21 14:30:20 by jhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fill_result(char **result, char *s1, char *s2)
{
	int		i;
	size_t	size1;
	size_t	size2;

	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	i = 0;
	while (i < size1)
	{
		(*result)[i] = s1[i];
		i++;
	}
	while (i < size1 + size2)
	{
		(*result)[i] = s2[i - size1];
		i++;
	}
	(*result)[i] = '\0';
}

char	*ft_mystrjoin(char *s1, char *s2, size_t size)
{
	char	*result;
	size_t	size1;
	size_t	size2;

	if (s1 == NULL)
		return (NULL);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	result = malloc((size1 + size2 + size) * sizeof(char) + 1);
	if (result == NULL)
	{
		ft_cmd_err("malloc");
		free(s1);
		return (NULL);
	}
	fill_result(&result, s1, s2);
	free (s1);
	return (result);
}
