/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:34:09 by tmillenn          #+#    #+#             */
/*   Updated: 2021/09/21 16:34:19 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_init_info(t_info *info, t_main *cmds)
{
	info->count_cmds = ft_count_commands(cmds);
	info->count_pipes = info->count_cmds - 1;
	info->fd = NULL;
	info->pids = NULL;
}

static void	ft_exec_one_cmd(t_main cmd, char ***envp)
{
	if (cmd.fd_input != 0)
		ft_dup2_and_close_fd(cmd.fd_input, 0, cmd.command[0]);
	if (cmd.fd_output != 1)
		ft_dup2_and_close_fd(cmd.fd_output, 1, cmd.command[0]);
	ft_exec_cmd(cmd.command, envp);
	exit(g_err_status);
}

static void	ft_one_cmd(t_main *cmds, char ***envp)
{
	int	pid;

	if (cmds->fd_input == 0 && cmds->fd_output == 1)
		return (ft_exec_cmd(cmds->command, envp));
	pid = fork();
	if (pid == 0)
		ft_exec_one_cmd(*cmds, envp);
	else if (pid < 0)
		return (ft_cmd_err("fork"));
	if (cmds->fd_input != 0)
		ft_close(cmds->fd_input, cmds->command[0]);
	if (cmds->fd_output != 1)
		ft_close(cmds->fd_output, cmds->command[0]);
	if (waitpid(pid, NULL, 0) == -1)
		ft_cmd_err(cmds->command[0]);
	if (cmds->double_input == 1)
		unlink(".tmp");
}

void	ft_execute_input(t_main *cmds, char ***envp)
{
	t_info	info;

	ft_init_info(&info, cmds);
	if (info.count_cmds == 1)
		ft_one_cmd(cmds, envp);
	else if (info.count_cmds == 0)
		return ;
	else
		ft_pipe(cmds, envp, &info);
}
