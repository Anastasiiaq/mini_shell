/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dollar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhizdahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:24:13 by jhizdahr          #+#    #+#             */
/*   Updated: 2021/09/21 14:28:07 by jhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_dollar_replace(char **str, char **env, t_param *param)
{
	int	n;

	(*str)++;
	if (ft_conditions_of_replacement(param, **str))
		return ("$\0");
	n = 0;
	while ((*str)[n] != '$' && (*str)[n] != ' ' && (*str)[n] != '\0' &&
	(*str)[n] != '\t' && (*str)[n] != '"' && (*str)[n] != 39)
		n++;
	while (*env != NULL)
	{
		if (ft_strncmp(*str, *env, n) == 0 && ((*env)[n] == '='))
		{
			while (**str != '$' && **str != ' ' && **str != '\0' && **str
				!= '\t' && **str != '"' && **str != 39)
				(*str)++;
			return (ft_replace_with_env(*env));
		}
		env++;
	}
	while (**str != '$' && **str != ' ' && **str != '\0' && **str
		!= '\t' && **str != '"' && **str != 39)
		(*str)++;
	return ("\0");
}

static char	*ft_parse_question(char **str)
{
	char	*res;

	(*str)++;
	(*str)++;
	res = ft_itoa(g_err_status);
	if (res == NULL)
	{
		ft_cmd_err("malloc");
		return (NULL);
	}
	return (res);
}

static void	ft_quotes_in_dollar(char **res, t_param *param, char **str)
{
	int	k;

	k = 0;
	while (k != 2)
	{
		if (**str == 39)
			k++;
		(*res)[param->i] = **str;
		(param->i)++;
		(*str)++;
	}
}

int	ft_dollar_parse(char **str, char **env, char **res, t_param *param)
{
	char	*buf;
	char	*copy;

	copy = *str;
	copy++;
	if ((*copy == 39) && param->in_dquotes == 1)
	{
		ft_quotes_in_dollar(res, param, str);
		return (1);
	}
	if (*copy == '?')
		buf = ft_parse_question(str);
	else
		buf = ft_dollar_replace(str, env, param);
	*res = ft_mystrjoin(*res, buf, ft_strlen(*str));
	if (*res == NULL)
		return (-1);
	if (*copy == '?')
		free(buf);
	while ((*res)[param->i] != '\0')
		(param->i)++;
	return (1);
}

int	ft_dollar_parse_special(char **str, char **env, char ***res, t_param *param)
{
	char	*buf;
	char	*copy;

	copy = *str;
	copy++;
	if ((*copy == 39) && param->in_dquotes == 1)
	{
		ft_quotes_in_dollar(&((*res)[param->j]), param, str);
		return (1);
	}
	if (*copy == '?')
		buf = ft_parse_question(str);
	else
		buf = ft_dollar_replace(str, env, param);
	(*res)[param->j] = ft_mystrjoin((*res)[param->j], buf, ft_strlen(*str));
	if (*res == NULL)
		return (-1);
	if (*copy == '?')
		free(buf);
	*res = ft_split((*res)[param->j], ' ');
	while ((*res)[param->j] != NULL)
		(param->j)++;
	/*while ((*res)[param->j][param->i] != '\0')
		(param->i)++;*/
	return (1);
}
