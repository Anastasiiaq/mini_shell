/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhizdahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 18:56:50 by jhizdahr          #+#    #+#             */
/*   Updated: 2021/04/24 14:21:01 by jhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*res_dst;
	char	*res_src;

	if (dst == src)
		return (dst);
	res_dst = (char *)dst;
	res_src = (char *)src;
	i = 0;
	while (i < n)
	{
		res_dst[i] = res_src[i];
		i++;
	}
	return (dst);
}
