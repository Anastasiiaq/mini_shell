/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:34:58 by tmillenn          #+#    #+#             */
/*   Updated: 2021/09/21 16:35:11 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_pipe_err(int **fd, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		ft_close(fd[i][0], "close");
		ft_close(fd[i][1], "close");
		i++;
	}
}

static int	**ft_create_fd_arr(int count_pipes)
{
	int	**fd;
	int	i;

	fd = (int **)malloc(sizeof(int *) * (count_pipes + 1));
	if (!fd)
	{
		ft_custom_err("pipe", "failed to allocate memory");
		return (0);
	}
	i = 0;
	while (i < count_pipes)
	{
		fd[i] = (int *)malloc(sizeof(int) * 2);
		if (!fd[i])
		{
			ft_free_int_line(fd, i);
			ft_custom_err("pipe", "failed to allocate memory");
			return (0);
		}
		i++;
	}
	fd[i] = NULL;
	return (fd);
}

static int	ft_create_pipes(int **fd, int count_pipes)
{
	int	i;

	i = 0;
	while (i < count_pipes)
	{
		if (pipe(fd[i]) != 0)
		{
			ft_pipe_err(fd, i);
			ft_free_int_line(fd, i);
			ft_cmd_err("pipe");
			return (-1);
		}
		i++;
	}
	return (0);
}

static pid_t	*ft_create_pids_arr(int count)
{
	pid_t	*pids;

	pids = (pid_t *)malloc(sizeof(pid_t) * count);
	if (!pids)
	{
		ft_custom_err("pipe", "failed to allocate memory");
		return (0);
	}
	return (pids);
}

void	ft_pipe(t_main *cmds, char ***envp, t_info *info)
{
	info->fd = ft_create_fd_arr(info->count_pipes);
	if (!info->fd)
		return ;
	if (ft_create_pipes(info->fd, info->count_pipes) != 0)
		return ;
	info->pids = ft_create_pids_arr(info->count_cmds);
	if (!info->pids)
	{
		ft_pipe_err(info->fd, info->count_pipes);
		ft_free_int_arr(info->fd);
		return ;
	}
	ft_create_forks(cmds, envp, info);
	ft_free_int_arr(info->fd);
	free(info->pids);
}
