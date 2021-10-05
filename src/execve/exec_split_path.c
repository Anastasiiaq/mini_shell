/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_split_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:27:54 by tmillenn          #+#    #+#             */
/*   Updated: 2021/09/21 16:28:05 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_check_dir(char *dir_name, char *cmd)
{
	DIR				*open_dir;
	struct dirent	*file_name;

	open_dir = opendir((const char *)dir_name);
	if (!open_dir)
		return (-1);
	file_name = readdir(open_dir);
	while (file_name != NULL)
	{
		if (!file_name)
		{
			closedir(open_dir);
			return (-1);
		}
		if (ft_strcmp(file_name->d_name, cmd) == 0
			&& ft_strcmp(file_name->d_name, ".") != 0
			&& ft_strcmp(file_name->d_name, "..") != 0)
		{
			closedir(open_dir);
			return (0);
		}
		file_name = readdir(open_dir);
	}
	closedir(open_dir);
	return (-1);
}

static void	ft_get_file_path(char *path, char **cmd)
{
	char	*full_path;
	char	*tmp;

	full_path = ft_strjoin(path, "/");
	if (!full_path)
		return (ft_custom_err(*cmd, "failed to allocate memory"));
	tmp = full_path;
	full_path = ft_strjoin(full_path, *cmd);
	free (tmp);
	if (!full_path)
		return (ft_custom_err(*cmd, "failed to allocate memory"));
	tmp = *cmd;
	*cmd = full_path;
	free (tmp);
}

int	ft_split_path(char *path_line, char **cmd, char **envp)
{
	int		i;
	char	**split_path;

	split_path = ft_split(path_line, ':');
	if (!split_path)
	{
		ft_custom_err(*cmd, "failed to allocate memory");
		return (-1);
	}
	i = 0;
	while (split_path[i] != NULL)
	{
		if (ft_check_dir(split_path[i], *cmd) == 0)
		{
			ft_get_file_path(split_path[i], cmd);
			ft_exec_some_cmd(cmd, envp);
			ft_free_arr(split_path);
			return (0);
		}
		i++;
	}
	ft_free_arr(split_path);
	return (1);
}
