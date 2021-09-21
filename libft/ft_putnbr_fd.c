/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhizdahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 11:30:41 by jhizdahr          #+#    #+#             */
/*   Updated: 2021/04/24 15:52:14 by jhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_size_of_number(unsigned int num)
{
	int				size;

	size = 0;
	while (num >= 10)
	{
		num = num / 10;
		size++;
	}
	return (size);
}

static int	power(int n, int st)
{
	int	i;
	int	result;

	i = 1;
	result = n;
	while (i < st)
	{
		result = result * n;
		i++;
	}
	return (result);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;
	char			buf;
	int				size;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		num = n * (-1);
	}
	else
		num = n;
	size = count_size_of_number(num);
	while (size > 0)
	{
		buf = num / power(10, size) + '0';
		num = num - power(10, size) * (buf - '0');
		ft_putchar_fd(buf, fd);
		size--;
	}
	ft_putchar_fd((num + '0'), fd);
}
