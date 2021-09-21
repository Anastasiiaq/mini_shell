/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirects_out.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhizdahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:10:50 by jhizdahr          #+#    #+#             */
/*   Updated: 2021/09/21 15:13:36 by jhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_init_param(char **str, t_param *param, int *append)
{
	*append = 0;
	param->in_quotes = 0;
	param->in_dquotes = 0;
	param->i = 0;
	(*str)++;
	if (**str == '>')
	{
		*append = 1;
		(*str)++;
	}
}

int	ft_form_filename(char **buf, t_param *p, char **env, char **str)
{
	while (**str != '\0')
	{
		if ((**str == ' ' || **str == '|' || **str == '\t' || **str == '>'
				|| **str == '<') && p->in_quotes != 1 && p->in_dquotes != 1)
			break ;
		if (**str == 39 || **str == '"')
		{
			if (ft_quotes_flags(&(p->in_quotes), &(p->in_dquotes), str) == 1)
				continue ;
		}
		if (**str == '$' && p->in_quotes != 1)
		{
			if (ft_dollar_parse(str, env, buf, p) == -1)
				return (-1);
			continue ;
		}
		if (**str == ' ' && p->in_quotes != 1 && p->in_dquotes != 1)
		{
			while (**str == ' ' || **str == '\t')
				(*str)++;
		}
		ft_str_assignment(buf, str, p);
	}
	return (1);
}

static int	ft_work_with_file_out(t_main *proper, int append, char *buf)
{
	if (proper->fd_output != 1)
	{
		if (close(proper->fd_output) == -1)
			return (-1);
	}
	if (append == 1)
	{
		proper->fd_output = open(buf, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (proper->fd_output == -1)
		{
			ft_cmd_err(buf);
			free(buf);
			return (-1);
		}
		return (1);
	}
	proper->fd_output = open(buf, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (proper->fd_output == -1)
	{
		ft_cmd_err(buf);
		free(buf);
		return (-1);
	}
	return (1);
}

int	ft_parse_redirect_output(char **str, char **env, t_main *proper)
{
	char	*buf;
	int		append;
	t_param	param;

	ft_init_param(str, &param, &append);
	if (ft_redirects_syntax_error(str) == -1)
		return (-1);
	buf = ft_calloc((ft_strlen(*str) + 1), sizeof(char));
	if (buf == NULL)
	{
		ft_cmd_err("malloc");
		return (-1);
	}
	if (ft_form_filename(&buf, &param, env, str) == -1)
		return (-1);
	if (ft_work_with_file_out(proper, append, buf) == -1)
		return (-1);
	free (buf);
	while (**str == ' ' || **str == '\t')
		(*str)++;
	return (1);
}
