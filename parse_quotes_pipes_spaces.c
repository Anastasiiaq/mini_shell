/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quotes_pipes_spaces.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhizdahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:08:21 by jhizdahr          #+#    #+#             */
/*   Updated: 2021/09/21 15:08:49 by jhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_quotes_flags(int *in_quotes, int *in_dquotes, char **str)
{
	if (**str == 39 && *in_quotes == 0 && *in_dquotes == 0)
	{
		*in_quotes = 1;
		(*str)++;
		return (1);
	}
	if (**str == 39 && *in_quotes == 1 && *in_dquotes == 0)
	{
		*in_quotes = 0;
		(*str)++;
		return (1);
	}
	if (**str == '"' && *in_dquotes == 0 && *in_quotes == 0)
	{
		*in_dquotes = 1;
		(*str)++;
		return (1);
	}
	if (**str == '"' && *in_dquotes == 1 && *in_quotes == 0)
	{
		*in_dquotes = 0;
		(*str)++;
		return (1);
	}
	return (0);
}

void	ft_parse_spaces(char **str, t_param *param)
{
	while (**str == ' ' || **str == '\t')
		(*str)++;
	if (**str == '\0')
		return ;
	(param->j)++;
	param->i = 0;
}

int	ft_parse_pipes(char **str, t_param *param, t_main **proper)
{
	(*proper)->next = ft_initialise();
	if ((*proper)->next == NULL)
		return (-1);
	(*proper) = (*proper)->next;
	param->i = 0;
	param->j = 0;
	(*str)++;
	while (**str == ' ' || **str == '\t')
		(*str)++;
	return (1);
}

void	ft_parse_spaces_in_dollar(t_param *param, char **arr, int i)
{
	param->j = i - 1;
	param->i = 0;
	while ((arr)[param->j][param->i] != '\0')
		(param->i)++;
}
