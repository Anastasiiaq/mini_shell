/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhizdahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:05:57 by jhizdahr          #+#    #+#             */
/*   Updated: 2021/09/21 15:06:16 by jhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_struct(t_main *res)
{
	t_main	*buf;
	int		i;

	while (res != NULL)
	{
		buf = res;
		i = 0;
		while (res->command[i] != NULL)
		{
			free(res->command[i]);
			i++;
		}
		free(res->command);
		res = res->next;
		free(buf);
	}
}
