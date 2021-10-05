/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:29:22 by tmillenn          #+#    #+#             */
/*   Updated: 2021/09/21 16:29:31 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_cmd_arg(char *arg)
{
	if (*arg == '-' || *arg == '+')
		arg++;
	while (*arg != '\0')
	{
		if (ft_isdigit(*arg) == 0)
			return (1);
		arg++;
	}
	return (0);
}

static void	ft_dgt_is_first_arg(int count_arg, char **cmd)
{
	int	num;

	if (count_arg > 3)
	{
		ft_putstr_fd("exit\n", 1);
		ft_custom_err(cmd[0], "too many arguments");
		return ;
	}
	else
	{
		ft_putstr_fd("exit\n", 1);
		num = ft_atoi(cmd[1]);
		g_err_status = (unsigned char)num;
		exit(num);
	}
}

void	ft_exit(char **cmd)
{
	int	count_arg;

	count_arg = ft_arr_len(cmd);
	if (count_arg == 2)
	{
		ft_putstr_fd("exit\n", 1);
		g_err_status = 0;
		exit(0);
	}
	else
	{
		if (ft_check_cmd_arg(cmd[1]) == 0)
			ft_dgt_is_first_arg(count_arg, cmd);
		else
		{
			ft_putstr_fd("exit\n", 1);
			ft_exit_err(cmd[0], "numeric argument required", cmd[1]);
			g_err_status = (unsigned char)(-1);
			exit(-1);
		}
	}
}
