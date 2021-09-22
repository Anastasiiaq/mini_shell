/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_dfl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:40:52 by tmillenn          #+#    #+#             */
/*   Updated: 2021/09/21 16:40:53 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_siginit(int sig)
{
	(void)sig;
	rl_replace_line("", 0);
	write(1, "\n", 1);
	rl_on_new_line();
	rl_redisplay();
	rl_replace_line("", 0);
	g_err_status = 1;
}

void	ft_signal(void)
{
	rl_catch_signals = 0;
	signal(SIGINT, ft_siginit);
	signal(SIGQUIT, SIG_IGN);
}

void	ft_signal_cmd(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}
