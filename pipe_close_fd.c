/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_close_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:34:31 by tmillenn          #+#    #+#             */
/*   Updated: 2021/09/21 16:34:44 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_close_pipe_fd(int *fd, char *cmd_name)
{
	ft_close(fd[0], cmd_name);
	ft_close(fd[1], cmd_name);
}

void	ft_close_pipes_fd_in_middle_fork(int position, t_info info)
{
	int	i;

	i = 0;
	while (i < info.count_pipes)
	{
		if (i != position - 1)
			ft_close(info.fd[i][0], "close");
		if (i != position)
			ft_close(info.fd[i][1], "close");
		i++;
	}
}

void	ft_close_pipes_fd_in_last_fork(t_main cmd, t_info info)
{
	int	i;

	i = 0;
	while (i < info.count_pipes - 1)
	{
		ft_close_pipe_fd(info.fd[i], cmd.command[0]);
		i++;
	}
}

void	ft_close_pipes_fd_in_first_fork(t_main cmd, t_info info)
{
	int	i;

	i = 1;
	while (i < info.count_pipes)
	{
		ft_close_pipe_fd(info.fd[i], cmd.command[0]);
		i++;
	}
}
