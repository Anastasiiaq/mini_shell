/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhizdahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 19:14:52 by jhizdahr          #+#    #+#             */
/*   Updated: 2021/04/25 19:09:18 by jhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*array;
	unsigned char	copy;

	copy = (unsigned char)c;
	array = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (array[i] == copy)
			return (&array[i]);
		i++;
	}
	return (NULL);
}
