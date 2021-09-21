/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dollar2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhizdahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:28:25 by jhizdahr          #+#    #+#             */
/*   Updated: 2021/09/21 14:29:07 by jhizdahr         ###   ########.fr       */
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
