/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhizdahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:59:33 by jhizdahr          #+#    #+#             */
/*   Updated: 2021/04/25 16:20:43 by jhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup (const char *s1)
{
	size_t	i;
	char	*result;
	size_t	size;

	i = 0;
	size = ft_strlen(s1);
	result = malloc(size * sizeof(char) + 1);
	if (result == NULL)
		return (NULL);
	while (i < size)
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
