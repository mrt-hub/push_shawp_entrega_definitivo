/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtorrado <mtorrado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 11:51:21 by mtorrado          #+#    #+#             */
/*   Updated: 2021/04/06 17:45:25 by mtorrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*t;
	t_list	*p;

	t = *lst;
	while (t != NULL)
	{
		p = t;
		t = t->next;
		(del)(p->content);
		free(p);
	}
	*lst = NULL;
	lst = NULL;
}
