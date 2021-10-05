/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:29:50 by tmillenn          #+#    #+#             */
/*   Updated: 2021/09/21 16:30:08 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_print_export(char **cpy_envp)
{
	int	i;

	while (*cpy_envp != NULL)
	{
		ft_putstr_fd("declare -x ", 1);
		i = 0;
		while ((*cpy_envp)[i] != '=' && (*cpy_envp)[i] != '\0')
		{
			ft_putchar_fd((*cpy_envp)[i], 1);
			i++;
		}
		if ((*cpy_envp)[i] == '=')
		{
			ft_putstr_fd("=\"", 1);
			i++;
			while ((*cpy_envp)[i] != '\0')
			{
				ft_putchar_fd((*cpy_envp)[i], 1);
				i++;
			}
			ft_putchar_fd('\"', 1);
		}
		ft_putchar_fd('\n', 1);
		cpy_envp++;
	}
}

static void	ft_swap_envp_line(char **str1, char **str2)
{
	char	*tmp;

	tmp = *str1;
	*str1 = *str2;
	*str2 = tmp;
}

static char	**ft_envp_cpy(char **envp)
{
	int		i;
	char	**tmp_envp;

	i = 0;
	tmp_envp = (char **)malloc(sizeof(char *) * ft_arr_len(envp));
	if (!tmp_envp)
	{
		ft_custom_err("export", "failed to allocate memory");
		return (NULL);
	}
	while (envp[i] != NULL)
	{
		tmp_envp[i] = (char *)malloc(sizeof(char) * (ft_strlen(envp[i]) + 1));
		if (!tmp_envp[i])
		{
			ft_free_line(tmp_envp, i);
			ft_custom_err("export", "failed to allocate memory");
			return (NULL);
		}
		ft_strlcpy(tmp_envp[i], (const char *)envp[i], ft_strlen(envp[i]) + 1);
		i++;
	}
	tmp_envp[i] = NULL;
	return (tmp_envp);
}

static void	ft_sort_export(char **cpy_envp)
{
	int		i;
	int		j;

	i = 0;
	if (cpy_envp != NULL)
	{
		while (cpy_envp[i + 1] != NULL)
		{
			j = i;
			while (cpy_envp[j] != NULL)
			{
				if (ft_strcmp(cpy_envp[i], cpy_envp[j]) == 1)
					ft_swap_envp_line(&cpy_envp[i], &cpy_envp[j]);
				j++;
			}
			i++;
		}
	}
}

void	ft_export_without_arg(char **envp)
{
	char	**cpy_envp;

	cpy_envp = ft_envp_cpy(envp);
	if (!cpy_envp)
		return ;
	ft_sort_export(cpy_envp);
	ft_print_export(cpy_envp);
	ft_free_arr(cpy_envp);
}
