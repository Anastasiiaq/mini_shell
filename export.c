/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_with_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:32:15 by tmillenn          #+#    #+#             */
/*   Updated: 2021/09/21 16:32:29 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_arrjoin_err(char **new_envp, int i, char *cmd_name)
{
	ft_free_line(new_envp, i);
	ft_custom_err(cmd_name, "failed to allocate memory");
}

void	ft_arrjoin(char ***envp, char *arg, char *cmd)
{
	int		i;
	char	**new_envp;

	i = 0;
	new_envp = (char **)malloc(sizeof(char *) * (ft_arr_len(*envp) + 1));
	if (!new_envp)
		return (ft_custom_err(cmd, "failed to allocate memory"));
	while ((*envp)[i] != NULL)
	{
		new_envp[i] = (char *)malloc(sizeof(char)
				* (ft_strlen((*envp)[i]) + 1));
		if (!new_envp[i])
			return (ft_arrjoin_err(new_envp, i, cmd));
		ft_strlcpy(new_envp[i], (const char *)(*envp)[i],
			ft_strlen((*envp)[i]) + 1);
		i++;
	}
	new_envp[i] = (char *)malloc(sizeof(char) * (ft_strlen(arg) + 1));
	if (!new_envp[i])
		return (ft_arrjoin_err(new_envp, i, cmd));
	ft_strlcpy(new_envp[i], (const char *)arg, ft_strlen(arg) + 1);
	i++;
	new_envp[i] = NULL;
	ft_free_arr(*envp);
	*envp = new_envp;
}

static void	ft_rewrite_val(char **envp, char *arg)
{
	int		numb_of_line;
	char	*new_line;

	if (ft_strchr(arg, '=') == NULL)
		return ;
	new_line = (char *)malloc(sizeof(char) * (ft_strlen(arg) + 1));
	if (!new_line)
	{
		ft_custom_err("export", "failed to allocate memory");
		return ;
	}
	ft_strlcpy(new_line, (const char *)arg, ft_strlen(arg) + 1);
	numb_of_line = ft_getenv_num_of_line(envp, arg);
	if (numb_of_line == -2)
	{
		free(new_line);
		ft_custom_err("export", "failed to allocate memory");
		return ;
	}
	free(envp[numb_of_line]);
	envp[numb_of_line] = new_line;
}

void	ft_export(char **cmd, char ***envp)
{
	int		i;
	int		check;

	i = 1;
	if (ft_arr_len(cmd) == 2)
		ft_export_without_arg(*envp);
	else if (ft_arr_len(cmd) > 2)
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
				ft_rewrite_val(*envp, cmd[i]);
			else if (check == -2)
				ft_custom_err(*cmd, "failed to allocate memory");
			else
				ft_arrjoin(envp, cmd[i], *cmd);
			i++;
		}
	}
}
