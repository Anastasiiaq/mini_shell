/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_set_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:26:53 by tmillenn          #+#    #+#             */
/*   Updated: 2021/09/21 16:26:54 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_add_home(char *cmd, char *dfl_dir)
{
	char	*line;

	cmd++;
	line = ft_strjoin((const char *)dfl_dir, (const char *)cmd);
	if (!line)
		return (NULL);
	return (line);
}

static void	ft_set_oldpwd(char *old_pwd, char ***envp, char *cmd)
{
	char	*str;
	int		num_line;

	num_line = ft_getenv_num_of_line(*envp, "OLDPWD");
	if (num_line == -2)
		return (ft_custom_err("cd", "failed to allocate memory"));
	str = ft_strjoin("OLDPWD=", old_pwd);
	free(old_pwd);
	if (str == NULL)
		return (ft_custom_err("cd", "failed to allocate memory"));
	if (num_line == -1)
	{
		ft_arrjoin(envp, str, cmd);
		free(str);
		return ;
	}
	free((*envp)[num_line]);
	(*envp)[num_line] = str;
}

static void	ft_set_pwd(char ***envp)
{
	char	*str;
	char	*tmp;
	int		num_line;

	str = NULL;
	str = getcwd(str, 0);
	if (!str)
		return (ft_cmd_err("cd"));
	num_line = ft_getenv_num_of_line(*envp, "PWD");
	if (num_line == -2)
		return (ft_custom_err("cd", "failed to allocate memory"));
	tmp = str;
	str = ft_strjoin("PWD=", str);
	free(tmp);
	if (!str)
		return (ft_custom_err("cd", "failed to allocate memory"));
	if (num_line == -1)
	{
		ft_arrjoin(envp, str, "cd");
		free(str);
		return ;
	}
	free((*envp)[num_line]);
	(*envp)[num_line] = str;
}

void	ft_set_param(char *old_pwd, char ***envp, char *cmd_name)
{
	ft_set_pwd(envp);
	ft_set_oldpwd(old_pwd, envp, cmd_name);
}
