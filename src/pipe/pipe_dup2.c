/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_dup2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:35:31 by tmillenn          #+#    #+#             */
/*   Updated: 2021/09/21 16:35:33 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_close(int fd, char *cmd_name)
{
	if (close(fd) != 0)
		ft_cmd_err(cmd_name);
}

void	ft_dup2(int oldfd, int newfd, char *cmd_name)
{
	if (dup2(oldfd, newfd) == -1)
	{
		ft_cmd_err(cmd_name);
		exit(1);
	}
}

void	ft_dup2_and_close_fd(int oldfd, int newfd, char *cmd_name)
{
	ft_dup2(oldfd, newfd, cmd_name);
	ft_close(oldfd, cmd_name);
}
