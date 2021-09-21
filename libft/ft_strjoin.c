/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhizdahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:45:48 by jhizdahr          #+#    #+#             */
/*   Updated: 2021/04/24 15:46:24 by jhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	size1;
	size_t	size2;
	size_t	i;

	if (s1 == NULL)
		return (NULL);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	result = malloc((size1 + size2) * sizeof(char) + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < size1)
	{
		result[i] = s1[i];
		i++;
	}
	while (i < size1 + size2)
	{
		result[i] = s2[i - size1];
		i++;
	}
	result[i] = '\0';
	return (result);
}
