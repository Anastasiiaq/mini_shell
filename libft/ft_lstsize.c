/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhizdahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 16:39:46 by jhizdahr          #+#    #+#             */
/*   Updated: 2021/04/23 16:45:33 by jhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	result;

	if (lst == NULL)
		return (0);
	result = 1;
	while (lst->next != NULL)
	{
		result++;
		lst = lst->next;
	}
	return (result);
}
