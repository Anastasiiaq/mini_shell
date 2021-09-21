/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhizdahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 16:27:24 by jhizdahr          #+#    #+#             */
/*   Updated: 2021/04/24 15:55:28 by jhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	copy;
	char	*result;
	int		counter;

	copy = (char)c;
	counter = 0;
	if (copy == '\0')
		return ((char *)&s[ft_strlen(s)]);
	i = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] == copy)
		{
			counter = 1;
			result = (char *)&s[i];
		}
		i++;
	}
	if (counter == 0)
		return (NULL);
	else
		return (result);
}
