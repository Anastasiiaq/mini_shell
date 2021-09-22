/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhizdahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:06:50 by jhizdahr          #+#    #+#             */
/*   Updated: 2021/09/21 15:07:39 by jhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_array(char **result, int i)
{
	while (i >= 0)
	{
		if (result[i] != NULL)
			free (result[i]);
		i--;
	}
	free (result);
}

char	*copy_str(char **array, int i, char **res)
{
	char	*str;

	str = ft_strdup(array[i]);
	if (str == NULL)
	{
		free_array(res, i);
		return (NULL);
	}
	if (array[i] != NULL)
		free (array[i]);
	return (str);
}

char	**ft_expand_array(char **array, int j, char *str)
{
	char	**res;
	int		i;

	i = 0;
	res = ft_calloc((j + 2), sizeof(char *));
	if (res == NULL)
		return (NULL);
	while (i < j)
	{
		res[i] = copy_str(array, i, res);
		if (res[i] == NULL)
			return (NULL);
		i++;
	}
	res[j] = ft_calloc((ft_strlen(str) + 1), sizeof(char));
	if (res[j] == NULL)
	{
		free_array(res, j);
		return (NULL);
	}
	free (array);
	res[j + 1] = NULL;
	return (res);
}

void	ft_initializate_parameters(t_param *param)
{
	param->in_quotes = 0;
	param->in_dquotes = 0;
	param->i = 0;
	param->j = 0;
}

void	ft_str_assignment(char **buf, char **str, t_param *p)
{
	(*buf)[p->i] = **str;
	(p->i)++;
	(*str)++;
}
