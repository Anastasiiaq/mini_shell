/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhizdahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:14:06 by jhizdahr          #+#    #+#             */
/*   Updated: 2021/04/25 19:38:04 by jhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	result = malloc(len * sizeof(char) + 1);
	if (result == NULL)
		return (NULL);
	j = (size_t)start;
	i = 0;
	while (i < len && s[j] != '\0')
	{
		result[i] = s[j];
		i++;
		j++;
	}
	result[i] = '\0';
	return (result);
}
