/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhizdahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:22:47 by jhizdahr          #+#    #+#             */
/*   Updated: 2021/09/21 14:23:31 by jhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_preparsing(char *str)
{
	while (*str != '\0')
	{
		if (*str == '"')
		{
			str++;
			while (*str != '"')
			{
				str++;
				if (*str == '\0')
					return (-1);
			}
		}
		if (*str == 39)
		{
			str++;
			while (*str != 39)
			{
				str++;
				if (*str == '\0')
					return (-1);
			}
		}
		str++;
	}
	return (1);
}

char	*ft_preparse_empty_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (str);
		i++;
	}
	free(str);
	return (NULL);
}
