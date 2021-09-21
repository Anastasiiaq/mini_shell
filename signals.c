/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:40:36 by tmillenn          #+#    #+#             */
/*   Updated: 2021/09/21 16:40:38 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_sigint_in_fork(int sig)
{
//	rl_replace_line("", 0);
//	write(1, "\n", 1);
//	rl_on_new_line();
//	rl_replace_line("", 0);
//	g_err_status = 130;
}

static void	ft_sigquit(int sig)
{
//	ft_putstr_fd("Quit: 3", 1);
//	write(1, "\n", 1);
//	g_err_status = 131;
}

void	ft_signal_in_fork(void)
{
//	signal(SIGINT, ft_sigint_in_fork);
//	signal(SIGQUIT, ft_sigquit);
}

static void	ft_sigint_here_doc(int sig)
{
//	write(1, "\n", 1);
//	g_err_status = 1;
//	exit(g_err_status);
}

void	ft_signal_here_doc(void)
{
//	signal(SIGINT, ft_sigint_here_doc);
//	signal(SIGQUIT, SIG_IGN);
}
