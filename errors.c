/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:27:36 by tmillenn          #+#    #+#             */
/*   Updated: 2021/09/21 16:27:38 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export_err(char *cmd, char *err, char *arg)
{
	ft_putstr_fd("🐚 minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putchar_fd('`', 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd("\': ", 2);
	ft_putstr_fd(err, 2);
	ft_putchar_fd('\n', 2);
	g_err_status = 1;
}

void	ft_cmd_err(char *cmd)
{
	ft_putstr_fd("🐚 minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putchar_fd('\n', 2);
	g_err_status = 1;
}

void	ft_custom_err(char *cmd, char *err)
{
	ft_putstr_fd("🐚 minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(err, 2);
	ft_putchar_fd('\n', 2);
	g_err_status = 1;
}

void	ft_cd_err(char *cmd, char *dir_name)
{
	ft_putstr_fd("🐚 minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(dir_name, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putchar_fd('\n', 2);
	g_err_status = 1;
}

void	ft_exit_err(char *cmd, char *err, char *arg)
{
	ft_putstr_fd("🐚 minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(err, 2);
	ft_putchar_fd('\n', 2);
	g_err_status = 1;
}
