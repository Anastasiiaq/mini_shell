/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhizdahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:15:03 by jhizdahr          #+#    #+#             */
/*   Updated: 2021/04/24 14:23:56 by jhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*res_dst;
	char	*res_src;

	res_dst = (char *)dst;
	res_src = (char *)src;
	if (dst <= src)
	{
		ft_memcpy(dst, src, n);
	}
	else
	{
		i = n;
		while (i > 0)
		{
			res_dst[i - 1] = res_src[i - 1];
			i--;
		}
	}
	return (dst);
}
