/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_unset_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:32:47 by tmillenn          #+#    #+#             */
/*   Updated: 2021/09/21 16:32:57 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_arg(char *cmd, char *arg)
{
	if (ft_isalpha(*arg) != 1 && *arg != '_')
	{
		ft_export_err(cmd, "not a valid identifier", arg);
		return (-1);
	}
	while (*arg != '\0' && *arg != '=')
	{
		if (ft_isalpha(*arg) != 1 && ft_isdigit(*arg) != 1 && *arg != '_')
		{
			ft_export_err(cmd, "not a valid identifier", arg);
			return (-1);
		}
		arg++;
	}
	return (0);
}

int	ft_check_double(char **envp, char *arg)
{
	char	*new_var_name;
	char	*var_name;

	new_var_name = ft_get_var_name(arg);
	if (!new_var_name)
		return (-2);
	while (*envp != NULL)
	{
		var_name = ft_get_var_name(*envp);
		if (!var_name)
		{
			free(new_var_name);
			return (-2);
		}
		if (ft_strcmp(var_name, new_var_name) == 0)
		{
			free(new_var_name);
			free(var_name);
			return (-1);
		}
		free(var_name);
		envp++;
	}
	free(new_var_name);
	return (0);
}
