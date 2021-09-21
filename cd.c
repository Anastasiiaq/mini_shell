/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:26:37 by tmillenn          #+#    #+#             */
/*   Updated: 2021/09/21 16:26:40 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_get_old_pwd(char **old_pwd, char *cmd_name)
{
	*old_pwd = NULL;
	*old_pwd = getcwd(*old_pwd, 0);
	if (!(*old_pwd))
	{
		ft_cmd_err(cmd_name);
		*old_pwd = "";
	}
}

static void	ft_chdir(int *dir, char *dst, char *cmd_name)
{
	*dir = chdir(dst);
	if (*dir != 0)
		ft_cd_err(cmd_name, dst);
}

static void	ft_get_default_dir(char **dfl_dir, char **envp)
{
	*dfl_dir = ft_getenv_line(envp, "HOME");
	if (!(*dfl_dir))
		*dfl_dir = "";
}

static void	ft_go_to_full_path(char **cmd, char *dfl_dir, int *dir)
{
	char	*str;

	str = ft_add_home(cmd[1], dfl_dir);
	if (!str)
		return (ft_custom_err(*cmd, "failed to allocate memory"));
	ft_chdir(dir, str, cmd[0]);
	free (str);
}

void	ft_cd(char **cmd, char ***envp)
{
	int		dir;
	char	*dfl_dir;
	char	*old_pwd;

	dir = -1;
	ft_get_default_dir(&dfl_dir, *envp);
	if (ft_strlen(dfl_dir) == 0)
		return ;
	ft_get_old_pwd(&old_pwd, cmd[0]);
	if (ft_arr_len(cmd) > 2)
	{
		if (cmd[1][0] != '~')
			ft_chdir(&dir, cmd[1], cmd[0]);
		else if (cmd[1][0] == '~' && (int)ft_strlen(cmd[1]) != 1)
			ft_go_to_full_path(cmd, dfl_dir, &dir);
		else
			ft_chdir(&dir, dfl_dir, cmd[0]);
	}
	else
		ft_chdir(&dir, dfl_dir, cmd[0]);
	if (dir == 0)
		ft_set_param(old_pwd, envp, *cmd);
	g_err_status = 0;
}
