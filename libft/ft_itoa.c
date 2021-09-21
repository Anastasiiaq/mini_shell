/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhizdahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:28:44 by jhizdahr          #+#    #+#             */
/*   Updated: 2021/06/01 15:03:37 by jhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_size_of_array(int n)
{
	int				size;
	unsigned int	num;

	size = 1;
	if (n < 0)
	{
		num = n * (-1);
		size = 2;
	}
	else
		num = n;
	while (num >= 10)
	{
		num = num / 10;
		size++;
	}
	return (size);
}

static void	itoa_helper(int n, char *result, int size)
{
	unsigned int	num;
	int				board;
	int				i;

	board = 0;
	if (n < 0)
	{
		result[0] = '-';
		num = n * (-1);
		board = 1;
	}
	else
		num = n;
	i = size - 1;
	while (i >= board)
	{
		result[i] = num % 10 + '0';
		num = num / 10;
		i--;
	}
	result[size] = '\0';
}

char	*ft_itoa(int n)
{
	char			*result;
	int				size;

	size = count_size_of_array(n);
	result = malloc(size * sizeof(char) + 1);
	if (result == NULL)
		return (NULL);
	itoa_helper(n, result, size);
	return (result);
}
