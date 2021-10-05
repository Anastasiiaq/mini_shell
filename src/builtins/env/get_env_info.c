/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:33:36 by tmillenn          #+#    #+#             */
/*   Updated: 2021/09/21 16:33:48 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_var_value(char **line)
{
	while (**line != '=')
		*line += 1;
	*line += 1;
}

static char	*ft_put_line(char **envp, int i, char *new_var_name, char *var_name)
{
	char	*tmp_line;

	tmp_line = envp[i];
	ft_var_value(&tmp_line);
	free(new_var_name);
	free(var_name);
	return (tmp_line);
}

char	*ft_getenv_line(char **envp, char *var)
{
	int		i;
	char	*new_var_name;
	char	*var_name;
	char	*line;

	i = 0;
	line = NULL;
	new_var_name = ft_get_var_name(var);
	if (!new_var_name)
		return (NULL);
	while (envp[i] != NULL)
	{
		var_name = ft_get_var_name(envp[i]);
		if (!var_name)
		{
			free(new_var_name);
			return (NULL);
		}
		if (ft_strcmp(new_var_name, var_name) == 0)
			return (ft_put_line(envp, i, new_var_name, var_name));
		free(var_name);
		i++;
	}
	free(new_var_name);
	return (line);
}

static int	ft_return_num_of_line(char *new_var_name, char *var_name, int num)
{
	free(new_var_name);
	free(var_name);
	return (num);
}

int	ft_getenv_num_of_line(char **envp, char *var)
{
	int		i;
	char	*new_var_name;
	char	*var_name;

	i = 0;
	new_var_name = ft_get_var_name(var);
	if (!new_var_name)
		return (-2);
	while (envp[i] != NULL)
	{
		var_name = ft_get_var_name(envp[i]);
		if (!var_name)
		{
			free(new_var_name);
			return (-2);
		}
		if (ft_strcmp(new_var_name, var_name) == 0)
			return (ft_return_num_of_line(new_var_name, var_name, i));
		free(var_name);
		i++;
	}
	free(new_var_name);
	return (-1);
}
