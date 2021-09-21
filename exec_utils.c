/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:28:26 by tmillenn          #+#    #+#             */
/*   Updated: 2021/09/21 16:28:38 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_arr_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	return (i + 1);
}

char	*ft_get_var_name(char *line)
{
	int		i;
	char	*var_name;

	i = 0;
	while (line[i] != '\0' && line[i] != '=')
		i++;
	var_name = (char *)malloc(sizeof(char) * (i + 1));
	if (!var_name)
		return (NULL);
	ft_strlcpy(var_name, line, sizeof(char) * (i + 1));
	return (var_name);
}

int	ft_count_commands(t_main *cmds)
{
	int	count;

	count = 0;
	while (cmds)
	{
		if (cmds->command[0] == NULL)
		{
			if (cmds->fd_input == 0 && cmds->fd_output == 1)
			{
				ft_error("syntax error near unexpected token `|'");
				return (0);
			}
		}
		count++;
		cmds = cmds->next;
	}
	return (count);
}
