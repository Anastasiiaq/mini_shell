/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhizdahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:44:51 by jhizdahr          #+#    #+#             */
/*   Updated: 2021/04/24 15:51:38 by jhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	size;
	char	n;

	n = '\n';
	if (s != NULL)
	{
		size = ft_strlen(s);
		write(fd, s, size);
		write(fd, &n, 1);
	}
}
