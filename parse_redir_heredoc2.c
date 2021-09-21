/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir_heredoc2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhizdahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:19:09 by jhizdahr          #+#    #+#             */
/*   Updated: 2021/09/21 15:19:51 by jhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_end_of_double_parse(int fd, t_main *proper, char *stop_word)
{
	if (close(fd) == -1)
	{
		ft_cmd_err("close");
		return (-1);
	}
	free (stop_word);
	proper->fd_input = open(".tmp", O_RDONLY, 0644);
	if (proper->fd_input == -1)
	{
		ft_cmd_err("heredoc");
		return (-1);
	}
	return (1);
}

void	ft_fill_the_line(char **res, char **buf)
{
	int	j;
	int	in_quotes;
	int	in_dquotes;

	j = 0;
	in_quotes = 0;
	in_dquotes = 0;
	while (**buf != '\0')
	{
		if (**buf == 39 || **buf == '"')
		{
			if (ft_quotes_flags(&in_quotes, &in_dquotes, buf) == 1)
				continue ;
		}
		(*res)[j] = **buf;
		j++;
		(*buf)++;
	}
}

char	*ft_dollar_in_redirect(char *line, char **env, char **res, t_param *par)
{
	char	*doll;

	doll = ft_calloc(ft_strlen(line) + 1, sizeof(char));
	if (doll == NULL)
	{
		free(line);
		ft_cmd_err("heredoc");
		return (NULL);
	}
	while (**res != '\0')
	{
		if (**res == '$')
		{
			if (ft_dollar_parse(res, env, &doll, par) == -1)
			{
				ft_free_some(line, doll, NULL);
				ft_cmd_err("malloc");
				return (NULL);
			}
			continue ;
		}
		ft_str_assignment(&doll, res, par);
	}
	return (doll);
}