/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhizdahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 11:39:09 by jhizdahr          #+#    #+#             */
/*   Updated: 2021/04/24 14:08:48 by jhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*new;

	if (lst == NULL)
		return (NULL);
	current = ft_lstnew(f(lst->content));
	if (current == NULL)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		new = malloc(sizeof(t_list));
		if (new == NULL)
		{
			ft_lstclear(&current, del);
			return (NULL);
		}
		new->content = f(lst->content);
		new->next = NULL;
		lst = lst->next;
		ft_lstadd_back(&current, new);
	}
	return (current);
}
