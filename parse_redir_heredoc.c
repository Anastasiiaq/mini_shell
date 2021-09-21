/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir_heredoc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhizdahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:16:28 by jhizdahr          #+#    #+#             */
/*   Updated: 2021/09/21 15:18:31 by jhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_quotes_line(char *line)
{
	char	*res;
	char	*buf;

	buf = line;
	res = ft_calloc(ft_strlen(line) + 1, sizeof(char));
	if (res == NULL)
	{
		free(line);
		ft_cmd_err("malloc");
		return (NULL);
	}
	ft_fill_the_line(&res, &buf);
	free(line);
	return (res);
}

static void	ft_form_heredoc(char **buf, t_param *p, char **str)
{
	while (**str != '\0')
	{
		if ((**str == ' ' || **str == '|' || **str == '\t' || **str == '>'
				|| **str == '<') && p->in_quotes != 1 && p->in_dquotes != 1)
			break;
		if (**str == 39 || **str == '"')
		{
			if (ft_quotes_flags(&(p->in_quotes), &(p->in_dquotes), str) == 1)
				continue ;
		}
		if (**str == ' ' && p->in_quotes != 1 && p->in_dquotes != 1)
		{
			while (**str == ' ' || **str == '\t')
				(*str)++;
		}
		ft_str_assignment(buf, str, p);
	}
}

static void	ft_child_process_heredoc(char *buf, char **env, int fd)
{
	char	*line;
	t_param	param;
	char	*doll;
	char	*res;

	ft_signal_here_doc();
	line = readline("> ");
	if (!line)
		exit (1);
	line = ft_quotes_line(line);
	if (line == NULL)
		exit (-1);
	while (ft_strcmp(line, buf) != 0)
	{
		res = line;
		ft_initializate_parameters(&param);
		doll = ft_dollar_in_redirect(line, env, &res, &param);
		if (doll == NULL)
			exit (-1);
		write(fd, doll, ft_strlen(doll));
		write(fd, "\n", 1);
		ft_free_some(line, doll, NULL);
		line = readline("> ");
		if (line == NULL)
			break ;
		line = ft_quotes_line(line);
	}
	free(line);
	exit (1);
}

static int	ft_fill_the_file(char *buf, char **env, int fd)
{
	pid_t	proc;
	int		status;

	proc = fork();
	if (proc == -1)
		return (-1);
	if (proc == 0)
		ft_child_process_heredoc(buf, env, fd);
	if (waitpid(proc, &status, 0) == -1)
		ft_cmd_err("waitpid");
	if (WIFEXITED(status) != 0)
		status = WEXITSTATUS(status);
	return (status);
}

int	ft_parse_double_input(char **str, char **env, t_main *proper)
{
	char	*stop_word;
	t_param	param;
	int		tmp;

	ft_initializate_parameters(&param);
	stop_word = ft_calloc((ft_strlen(*str) + 1), sizeof(char));
	if (stop_word == NULL)
	{
		ft_cmd_err("malloc");
		return (-1);
	}
	ft_form_heredoc(&stop_word, &param, str);
	tmp = open(".tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (tmp == -1)
	{
		ft_cmd_err("heredoc");
		return (-1);
	}
	if (ft_fill_the_file(stop_word, env, tmp) == -1)
		return (-1);
	if (ft_end_of_double_parse(tmp, proper, stop_word) == -1)
		return (-1);
	return (1);
}
