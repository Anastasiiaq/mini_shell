/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhizdahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:31:49 by jhizdahr          #+#    #+#             */
/*   Updated: 2021/09/21 15:04:22 by jhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_copy_array(char ***res, char **envp, int i)
{
	int	j;

	j = 0;
	while (envp[i][j] != '\0')
	{
		(*res)[i][j] = envp[i][j];
		j++;
	}
	(*res)[i][j] = '\0';
}

char	**ft_get_env(char **envp)
{
	char	**res;
	int		i;
	size_t	size;

	i = 0;
	while (envp[i] != NULL)
		i++;
	res = malloc(sizeof(char *) * (i + 1));
	if (res == NULL)
		ft_critical_error("Memory error");
	i = 0;
	while (envp[i] != NULL)
	{
		size = ft_strlen(envp[i]);
		res[i] = (char *)malloc(sizeof(char) * (size + 1));
		if (res[i] == NULL)
			ft_critical_error("Memory error");
		ft_copy_array(&res, envp, i);
		i++;
	}
	res[i] = NULL;
	return (res);
}
