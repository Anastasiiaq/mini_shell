/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:42:35 by tmillenn          #+#    #+#             */
/*   Updated: 2021/09/21 16:42:37 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_get_name(char *new_var_name, char *line)
{
	char	*name;

	name = ft_get_var_name(line);
	if (!name)
	{
		free(new_var_name);
		ft_custom_err("unset", "failed to allocate memory");
		return (NULL);
	}
	return (name);
}

static char	*ft_malloc_new_line(char *old_line,
		char *var_name, char *new_var_name)
{
	char	*new_line;

	new_line = (char *)malloc(sizeof(char) * (ft_strlen(old_line) + 1));
	if (!new_line)
	{
		free(new_var_name);
		free(var_name);
		ft_custom_err("unset", "failed to allocate memory");
		return (NULL);
	}
	return (new_line);
}

static void	ft_new_envp(char **envp, char *new_var_name, char **new_envp)
{
	int		i;
	char	*var_name;

	i = 0;
	while (*envp != NULL)
	{
		var_name = ft_get_name(new_var_name, *envp);
		if (!var_name)
			return ;
		if (ft_strcmp(var_name, new_var_name) == 0)
		{
			envp++;
			free(var_name);
			continue ;
		}
		new_envp[i] = ft_malloc_new_line(*envp, var_name, new_var_name);
		if (!new_envp[i])
			return (ft_free_line(new_envp, i));
		ft_strlcpy(new_envp[i], *envp, ft_strlen(*envp) + 1);
		free(var_name);
		i++;
		envp++;
	}
	new_envp[i] = NULL;
}

static void	ft_del_line(char ***envp, char *arg)
{
	char	**new_envp;
	char	*new_var_name;
	char	**tmp;

	new_envp = (char **)malloc(sizeof(char *) * (ft_arr_len(*envp) - 1));
	new_var_name = ft_get_var_name(arg);
	if (!new_envp || !new_var_name)
		return (ft_custom_err("unset", "failed to allocate memory"));
	tmp = *envp;
	ft_new_envp(*envp, new_var_name, new_envp);
	*envp = new_envp;
	ft_free_arr(tmp);
	free(new_var_name);
}

void	ft_unset(char **cmd, char ***envp)
{
	int	i;
	int	check;

	i = 1;
	if (ft_arr_len(cmd) > 2)
	{
		while (cmd[i] != NULL)
		{
			if (ft_check_arg(cmd[0], cmd[i]) != 0)
			{
				i++;
				continue ;
			}
			check = ft_check_double(*envp, cmd[i]);
			if (check == -1)
				ft_del_line(envp, cmd[i]);
			else if (check == -2)
				ft_custom_err(*cmd, "failed to allocate memory");
			i++;
		}
	}
	g_err_status = 0;
}
