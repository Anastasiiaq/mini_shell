/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhizdahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 20:01:04 by jhizdahr          #+#    #+#             */
/*   Updated: 2021/04/24 13:13:12 by jhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				result;
	unsigned char	*array1;
	unsigned char	*array2;
	unsigned long	i;

	array1 = (unsigned char *)s1;
	array2 = (unsigned char *)s2;
	i = 0;
	result = 0;
	while (i < n)
	{
		if (array1[i] != array2[i])
		{
			result = array1[i] - array2[i];
			break ;
		}
		i++;
	}
	return (result);
}
