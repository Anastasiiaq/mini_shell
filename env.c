/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:27:23 by tmillenn          #+#    #+#             */
/*   Updated: 2021/09/21 16:27:26 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strchr((const char *)envp[i], '=') != NULL)
		{
			ft_putstr_fd(envp[i], 1);
			write(1, "\n", 1);
		}
		i++;
	}
	g_err_status = 0;
}
