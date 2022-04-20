/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtorrado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:11:17 by mtorrado          #+#    #+#             */
/*   Updated: 2021/03/31 13:52:05 by mtorrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newlstt;

	if (!lst || !f)
		return (NULL);
	newlst = ft_lstnew(f(lst->content));
	if (!newlst)
		ft_lstclear(&lst, del);
	newlstt = newlst;
	lst = lst->next;
	while (lst)
	{
		newlst = ft_lstnew(f(lst->content));
		if (!newlstt)
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&newlstt, del);
			break ;
		}
		lst = lst->next;
		ft_lstadd_back(&newlstt, newlst);
	}
	return (newlstt);
}
