/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhizdahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:16:04 by jhizdahr          #+#    #+#             */
/*   Updated: 2021/04/24 16:03:43 by jhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*result;
	unsigned char	copy;

	result = (unsigned char *)b;
	i = 0;
	copy = (unsigned char)c;
	while (i < len)
	{
		result[i] = copy;
		i++;
	}
	return (b);
}
