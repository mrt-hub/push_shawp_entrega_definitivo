/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtorrado <mtorrado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 19:01:44 by mtorrado          #+#    #+#             */
/*   Updated: 2022/04/20 18:32:58 by mtorrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_dlstsize(t_dlist *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_dlist	*ft_dlstlast(t_dlist *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_dlstadd_back(t_dlist **lst, t_dlist *new)
{
	t_dlist	*t;

	if (*lst != NULL)
	{
		t = ft_dlstlast(*lst);
		t->next = &*new;
	}
	else
		*lst = new;
}

void	ft_dlstadd_front(t_dlist **alst, t_dlist *new)
{
	if (alst == NULL || new == NULL)
		return ;
	new -> next = *alst;
	*alst = new;
}

t_dlist	*ft_dlstnew(int content)
{
	t_dlist	*res;

	res = (t_dlist *)malloc(sizeof(t_dlist));
	if (!res)
		return (NULL);
	res->next = NULL;
	res->content = content;
	return (res);
}
