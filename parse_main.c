/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhizdahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:14:19 by jhizdahr          #+#    #+#             */
/*   Updated: 2021/09/21 14:21:41 by jhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_if_special_symbol(char symb)
{
	if (symb == '$' || symb == ' ' || symb == '\t' || symb == '|' || symb == '>'
		|| symb == '<')
		return (1);
	return (0);
}

static int	ft_choose_parsing(char **str, t_param *par, t_main **proper, char
**env)
{
	if (par->in_quotes != 1 && **str == '$')
		return (ft_dollar_parse_special(str, env, &((*proper)->command), par));
	else if (par->in_quotes != 1 && par->in_dquotes != 1)
	{
		if ((**str == ' ' || **str == '\t'))
		{
			ft_parse_spaces(str, par);
			return (1);
		}
		if (**str == '|')
			return (ft_parse_pipes(str, par, proper));
		if (**str == '>')
			return (ft_parse_redirect_output(str, env, *proper));
		if (**str == '<')
			return (ft_parse_redirect_input(str, env, *proper));
	}
	else
	{
		((*proper)->command)[par->j][par->i] = **str;
		(par->i)++;
		(*str)++;
	}
	return (1);
}

static int	ft_array_extension(t_param param, char *str, t_main *proper)
{
	proper->command = ft_expand_array(proper->command, param.j, str);
	if (proper->command == NULL)
	{
		ft_cmd_err("malloc");
		return (-1);
	}
	return (1);
}

static int	ft_parse_str(char **str, t_param param, t_main *proper, char **env)
{
	while (**str)
	{
		if (proper->command[param.j] == NULL && **str != '>' && **str != '<'
			&& **str != '|')
		{
			if (ft_array_extension(param, *str, proper) == -1)
				return (-1);
		}
		if (**str == 39 || **str == '"')
		{
			if (ft_quotes_flags(&param.in_quotes, &param.in_dquotes, str) == 1)
				continue ;
		}
		if (ft_if_special_symbol(**str) && param.in_quotes != 1)
		{
			if (ft_choose_parsing(str, &param, &proper, env) == -1)
				return (-1);
			continue ;
		}
		(proper->command)[param.j][param.i] = **str;
		param.i++;
		(*str)++;
	}
	return (1);
}

t_main	*ft_parsing(char *str, char **env)
{
	t_param		param;
	t_main		*res;
	t_main		*proper;
	int			err;

	res = ft_initialise();
	if (res == NULL)
		return (NULL);
	proper = res;
	ft_initializate_parameters(&param);
	if (ft_preparsing(str) == -1)
	{
		ft_custom_err("input", "unclosed quotes");
		ft_free_struct(res);
		return (NULL);
	}
	while (*str == ' ' || *str == '\t')
		str++;
	err = ft_parse_str(&str, param, proper, env);
	if (err == -1)
	{
		ft_free_struct(res);
		return (NULL);
	}
	return (res);
}
