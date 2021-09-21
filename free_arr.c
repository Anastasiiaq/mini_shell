/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:33:12 by tmillenn          #+#    #+#             */
/*   Updated: 2021/09/21 16:33:24 by tmillenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_free_line(char **arr, int count)
{
	int	i;

	i = 0;
	while (arr[i] != NULL && i < count)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_free_int_arr(int **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_free_int_line(int **arr, int count)
{
	int	i;

	i = 0;
	while (arr[i] != NULL && i < count)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
