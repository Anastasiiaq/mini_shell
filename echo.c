/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:27:09 by tmillenn          #+#    #+#             */
/*   Updated: 2021/09/21 16:27:12 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(char **cmd)
{
	int	i;

	i = 1;
	if (ft_arr_len(cmd) > 2)
	{
		while (cmd[i] != NULL && ft_strcmp(cmd[i], "-n") == 0)
			i++;
		while (cmd[i] != NULL)
		{
			ft_putstr_fd(cmd[i], 1);
			i++;
			if (cmd[i] != NULL)
				write(1, " ", 1);
		}
		if (ft_strcmp(cmd[1], "-n") != 0)
			write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
	g_err_status = 0;
}
