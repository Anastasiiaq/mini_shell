/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:39:27 by tmillenn          #+#    #+#             */
/*   Updated: 2021/09/21 16:40:08 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(void)
{
	char	*dir;

	dir = NULL;
	dir = getcwd(dir, 0);
	if (!dir)
		return (ft_cmd_err("pwd"));
	ft_putstr_fd(dir, 1);
	ft_putchar_fd('\n', 1);
	free(dir);
	g_err_status = 0;
}
