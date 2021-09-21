/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:39:07 by tmillenn          #+#    #+#             */
/*   Updated: 2021/09/21 16:39:10 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_wait(t_info info)
{
	int	i;

	i = 0;
	while (i < info.count_pipes)
	{
		ft_close(info.fd[i][0], "close");
		ft_close(info.fd[i][1], "close");
		i++;
	}
	i = 0;
	while (i < info.count_cmds)
	{
		if (waitpid(info.pids[i], NULL, 0) == -1)
			ft_cmd_err("pipe");
		i++;
	}
}

static void	ft_unlink_tmp(t_main *cmds)
{
	t_main	*tmp;

	tmp = cmds;
	while (tmp)
	{
		if (tmp->double_input == 1)
			unlink(".tmp");
		tmp = tmp->next;
	}
}

static void	ft_close_fd(t_main *cmds)
{
	t_main	*tmp;

	tmp = cmds;
	while (tmp)
	{
		if (tmp->fd_input != 0)
			ft_close(tmp->fd_input, "close");
		if (tmp->fd_output != 1)
			ft_close(tmp->fd_output, "close");
		tmp = tmp->next;
	}
}

void	ft_create_forks(t_main *cmds, char ***envp, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->count_cmds)
	{
		info->pids[i] = fork();
		if (info->pids[i] == 0)
			ft_choose_cmd_position(i, cmds, envp, *info);
		else if (info->pids[i] < 0)
			return (ft_cmd_err("fork"));
		i++;
	}
	ft_wait(*info);
	ft_close_fd(cmds);
	ft_unlink_tmp(cmds);
}
