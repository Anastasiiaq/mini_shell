/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirects_in.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhizdahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:14:04 by jhizdahr          #+#    #+#             */
/*   Updated: 2021/09/21 15:15:46 by jhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_work_with_file_in(t_main *proper, char *buf)
{
	if (proper->fd_input != 0)
	{
		if (close(proper->fd_input) == -1)
		{
			ft_cmd_err("close");
			return (-1);
		}
	}
	proper->fd_input = open(buf, O_RDONLY, 0644);
	if (proper->fd_input == -1)
	{
		ft_cmd_err(buf);
		free (buf);
		return (-1);
	}
	return (1);
}

void	ft_free_some(char *arr1, char *arr2, char *arr3)
{
	if (arr1 != NULL)
		free(arr1);
	if (arr2 != NULL)
		free(arr2);
	if (arr3 != NULL)
		free(arr3);
}

static int	ft_parse_usual(char **str, char **env, t_main *proper)
{
	char	*buf;
	t_param	param;

	param.in_quotes = 0;
	param.in_dquotes = 0;
	param.i = 0;
	buf = ft_calloc((ft_strlen(*str) + 1), sizeof(char));
	if (buf == NULL)
		return (-1);
	if (ft_form_filename(&buf, &param, env, str) == -1)
		return (-1);
	if (ft_work_with_file_in(proper, buf) == -1)
		return (-1);
	free (buf);
	return (1);
}

int	ft_parse_redirect_input(char **str, char **env, t_main *proper)
{
	int	heredoc;

	heredoc = 0;
	(*str)++;
	if (**str == '<')
	{
		heredoc = 1;
		(*str)++;
	}
	if (ft_redirects_syntax_error(str) == -1)
		return (-1);
	if (heredoc == 1)
	{
		proper->double_input = 1;
		if (ft_parse_double_input(str, env, proper) == -1)
			return (-1);
		return (1);
	}
	if (ft_parse_usual(str, env, proper) == -1)
		return (-1);
	while (**str == ' ' || **str == '\t')
		(*str)++;
	return (1);
}
