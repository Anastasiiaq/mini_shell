/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhizdahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:06:01 by jhizdahr          #+#    #+#             */
/*   Updated: 2021/04/24 14:36:51 by jhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	copy;

	copy = (char)c;
	if (copy == '\0')
		return ((char *)&s[ft_strlen(s)]);
	i = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] == copy)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
