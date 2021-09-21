/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhizdahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 17:07:20 by jhizdahr          #+#    #+#             */
/*   Updated: 2021/04/24 14:39:03 by jhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	needle_size;

	needle_size = ft_strlen(needle);
	if (needle_size == 0)
		return ((char *)&haystack[0]);
	i = 0;
	if (len > ft_strlen(haystack))
		len = ft_strlen(haystack);
	while ((i + needle_size - 1) < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && j < needle_size)
		{
			j++;
		}
		if (j == needle_size)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
