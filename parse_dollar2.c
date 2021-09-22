/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dollar2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhizdahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:28:25 by jhizdahr          #+#    #+#             */
/*   Updated: 2021/09/22 13:21:50 by jhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_replace_with_env(char *replace)
{
	replace = ft_strchr(replace, '=');
	replace++;
	return (replace);
}

int	ft_conditions_of_replacement(t_param *param, char symbol)
{
	if (param->in_dquotes == 1 && symbol == '"')
	{
		((param->i)++);
		return (1);
	}
	if (symbol == '$' || symbol == ' ' || symbol == '\0' || symbol == '\t')
	{
		((param->i)++);
		return (1);
	}
	return (0);
}

static char	*ft_arr_utils(char *str, char **buf, char **arr)
{
	char	*res;

	res = ft_strdup(str);
	if (res == NULL)
	{
		ft_cmd_err("malloc");
		ft_free_arr(buf);
		ft_free_arr(arr);
		return (NULL);
	}
	return (res);
}

static int	ft_make_arg(char **last, char ***result, t_param *param, char **buf)
{
	int	i;
	int	j;

	i = 0;
	while (i != param->j)
	{
		(*result)[i] = ft_arr_utils(last[i], buf, *result);
		if ((*result)[i] == NULL)
			return (-1);
		i++;
	}
	j = 0;
	while (buf[j] != NULL)
	{
		(*result)[i] = ft_arr_utils(buf[j], buf, *result);
		if ((*result)[i] == NULL)
			return (-1);
		i++;
		j++;
	}
	(*result)[i] = NULL;
	param->j = i;
	return (1);
}

char	**ft_change_arg(char **last, char *str, t_param *param)
{
	char	**result;
	char	**buf;
	int		size;

	size = 0;
	buf = ft_split(str, ' ');
	if (buf == NULL)
		return (NULL);
	while (buf[size] != NULL)
		size++;
	size = size + param->j + 1;
	result = malloc(sizeof(char *) * size + 1);
	if (result == NULL)
	{
		ft_cmd_err("malloc");
		ft_free_arr(buf);
		return (NULL);
	}
	if (ft_make_arg(last, &result, param, buf) == -1)
		return (NULL);
	ft_free_arr(buf);
	ft_free_arr(last);
	return (result);
}
