/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_exec_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:37:10 by tmillenn          #+#    #+#             */
/*   Updated: 2021/09/21 16:37:48 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_cmd_is_first(t_main cmd, char ***envp, t_info info)
{
	ft_close(info.fd[0][0], cmd.command[0]);
	ft_close_pipes_fd_in_first_fork(cmd, info);
	if (cmd.fd_input != 0)
		ft_dup2_and_close_fd(cmd.fd_input, 0, cmd.command[0]);
	if (cmd.fd_output == 1)
		ft_dup2(info.fd[0][1], 1, cmd.command[0]);
	else
		ft_dup2_and_close_fd(cmd.fd_output, 1, cmd.command[0]);
	ft_close(info.fd[0][1], cmd.command[0]);
	ft_exec_cmd(cmd.command, envp);
	exit(g_err_status);
}

static int	ft_cmd_is_last(t_main cmd, char ***envp, t_info info)
{
	ft_close(info.fd[info.count_pipes - 1][1], cmd.command[0]);
	ft_close_pipes_fd_in_last_fork(cmd, info);
	if (cmd.fd_output != 1)
		ft_dup2_and_close_fd(cmd.fd_output, 1, cmd.command[0]);
	if (cmd.fd_input == 0)
		ft_dup2(info.fd[info.count_pipes - 1][0], 0, cmd.command[0]);
	else
		ft_dup2_and_close_fd(cmd.fd_input, 0, cmd.command[0]);
	ft_close(info.fd[info.count_pipes - 1][0], cmd.command[0]);
	ft_exec_cmd(cmd.command, envp);
	exit(g_err_status);
}

static int	ft_cmd_is_middle(t_main *cmds, char ***envp,
		int position, t_info info)
{
	int	i;

	i = 0;
	while (i < position)
	{
		cmds = cmds->next;
		i++;
	}
	ft_close_pipes_fd_in_middle_fork(*cmds, position, info);
	if (cmds->fd_input == 0)
		ft_dup2(info.fd[position - 1][0], 0, cmds->command[0]);
	else
		ft_dup2_and_close_fd(cmds->fd_input, 0, cmds->command[0]);
	ft_close(info.fd[position - 1][0], "close");
	if (cmds->fd_output == 1)
		ft_dup2(info.fd[position][1], 1, cmds->command[0]);
	else
		ft_dup2_and_close_fd(cmds->fd_output, 1, cmds->command[0]);
	ft_close(info.fd[position][1], "close");
	ft_exec_cmd(cmds->command, envp);
	exit(g_err_status);
}

void	ft_choose_cmd_position(int position, t_main *cmds,
							   char ***envp, t_info info)
{
	if (position == 0)
		ft_cmd_is_first(*cmds, envp, info);
	else if (position == info.count_cmds - 1)
	{
		while (cmds->next)
			cmds = cmds->next;
		ft_cmd_is_last(*cmds, envp, info);
	}
	else
		ft_cmd_is_middle(cmds, envp, position, info);
}
