/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhizdahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:03:44 by jhizdahr          #+#    #+#             */
/*   Updated: 2021/04/24 15:50:56 by jhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	size_t	size;
	size_t	i;

	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	result = malloc(size * sizeof(char) + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
