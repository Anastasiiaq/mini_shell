/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhizdahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:09:38 by jhizdahr          #+#    #+#             */
/*   Updated: 2021/09/21 15:09:53 by jhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_error(char *str)
{
	size_t	size;

	size = ft_strlen(str);
	write(2, str, size);
	write(2, "\n", 1);
}

void	ft_critical_error(char *str)
{
	size_t	size;

	size = ft_strlen(str);
	write(2, str, size);
	write(2, "\n", 1);
	exit(1);
}

int	ft_redirects_syntax_error(char **str)
{
	while (**str != '\0')
	{
		if (**str == '|')
		{
			ft_error("minishell: syntax error near unexpected token `|'");
			return (-1);
		}
		else if (**str == '>')
		{
			ft_error("minishell: syntax error near unexpected token `>'");
			return (-1);
		}
		else if (**str == '<')
		{
			ft_error("minishell: syntax error near unexpected token `<'");
			return (-1);
		}
		else if (**str == ' ' || **str == '\t')
			(*str)++;
		else
			return (1);
	}
	ft_error("minishell: syntax error near unexpected token `newline'");
	return (-1);
}
