/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhizdahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 19:56:29 by jhizdahr          #+#    #+#             */
/*   Updated: 2021/04/24 14:23:08 by jhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*res_dst;
	unsigned char	*res_src;
	unsigned char	copy;

	res_dst = (unsigned char *)dst;
	res_src = (unsigned char *)src;
	copy = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		res_dst[i] = res_src[i];
		if (res_src[i] == copy)
		{
			return (&res_dst[i + 1]);
		}
		i++;
	}
	return (NULL);
}
