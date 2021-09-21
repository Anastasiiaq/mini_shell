/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:28:56 by tmillenn          #+#    #+#             */
/*   Updated: 2021/09/21 16:29:12 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_wait_exec_fork(int pid, int *status, char *cmd_name)
{
	if (waitpid(pid, status, 0) == -1)
		ft_cmd_err(cmd_name);
	if (WIFEXITED(*status) != 0)
	{
		*status = WEXITSTATUS(*status);
		g_err_status = *status;
	}
}

void	ft_exec_some_cmd(char **cmd, char **envp)
{
	int	pid;
	int	status;

	status = 0;
	ft_signal_in_fork();
	pid = fork();
	if (pid == 0)
	{
		g_err_status = 0;
		if (execve(cmd[0], cmd, envp) == -1)
		{
			ft_cmd_err(cmd[0]);
			g_err_status = 1;
			exit(1);
		}
	}
	else if (pid < 0)
	{
		ft_cmd_err(cmd[0]);
		g_err_status = 1;
		return ;
	}
	ft_wait_exec_fork(pid, &status, cmd[0]);
}

static int	ft_check_path(char *cmd)
{
	size_t	len;
	int		i;
	int		num;

	i = 0;
	num = 0;
	len = ft_strlen(cmd);
	while (*cmd != '\0')
	{
		if (*cmd == '.' || *cmd == '/')
		{
			if (*cmd == '/')
				num++;
			i++;
		}
		cmd++;
	}
	if ((len == (size_t)i && num != 0) || (len != (size_t)i && num != 0))
		return (1);
	return (0);
}

static int	ft_check_slash(char *cmd)
{
	size_t	len;
	int		i;
	int		count_dot;
	int		count_symb;

	i = 0;
	count_dot = 0;
	count_symb = 0;
	len = ft_strlen(cmd);
	while (*cmd != '\0')
	{
		if (*cmd == '.')
			count_dot++;
		if (*cmd == '/')
			i++;
		if (*cmd == '.' || *cmd == '/')
			count_symb++;
		cmd++;
	}
	if (len == (size_t)count_symb && count_dot < 3)
		return (1);
	return (0);
}

void	ft_execve(char **cmd, char **envp)
{
	int		split_path;
	char	*path_line;

	if (ft_check_path(*cmd) == 0)
	{
		path_line = ft_getenv_line(envp, "PATH");
		if (path_line)
		{
			split_path = ft_split_path(path_line, cmd, envp);
			if (split_path == 0 || split_path == -1)
				return ;
		}
		ft_custom_err(*cmd, "command not found");
		g_err_status = 127;
	}
	else if (ft_check_slash(*cmd) == 1)
	{
		ft_custom_err(*cmd, "is a directory");
		g_err_status = 126;
	}
	else
		ft_exec_some_cmd(cmd, envp);
}
