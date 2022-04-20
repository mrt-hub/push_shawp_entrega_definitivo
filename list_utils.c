/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtorrado <mtorrado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:26:48 by mtorrado          #+#    #+#             */
/*   Updated: 2022/04/20 18:27:25 by mtorrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist	*fill_list(t_dlist **stack_a, char **split_arg)
{
	long	num;
	int		i;

	i = 0;
	while (split_arg[i])
	{
		num = ft_int_atoi(split_arg[i]);
		if (num > 2147483647 || num < -2147483648)
			ft_exit_error("Error\n", 1);
		ft_dlstadd_back(stack_a, ft_dlstnew(num));
		i++;
	}
	return (*stack_a);
}

t_dlist	*ft_lst_dup(t_dlist *stack)
{
	t_dlist	*tmp1;
	t_dlist	*tmp2;

	tmp1 = malloc(sizeof(t_dlist));
	ft_bzero(tmp1, sizeof(t_dlist));
	tmp2 = tmp1;
	while (stack)
	{
		tmp1->content = stack->content;
		if (stack->next)
		{
			tmp1->next = malloc(sizeof(t_dlist));
			ft_bzero(tmp1->next, sizeof(t_dlist));
			tmp1 = tmp1->next;
		}
		stack = stack->next;
	}
	tmp1 = tmp2;
	return (tmp1);
}

void	ft_lstswp(t_dlist *x, t_dlist *y)
{
	int	tmp;

	tmp = x->content;
	x->content = y->content;
	y->content = tmp;
}

t_dlist	*ft_lstsort(t_dlist *stack)
{
	t_dlist	*base;
	t_dlist	*tmp;
	t_dlist	*cmp;

	base = NULL;
	base = stack;
	tmp = NULL;
	cmp = NULL;
	while (base->next)
	{
		cmp = base;
		tmp = base->next;
		while (tmp)
		{
			if (cmp->content > tmp->content)
				cmp = tmp;
			tmp = tmp->next;
		}
		ft_lstswp(base, cmp);
		base = base->next;
	}
	return (stack);
}

t_dlist	*ft_lstsort_reverse(t_dlist *stack)
{
	t_dlist	*base;
	t_dlist	*tmp;
	t_dlist	*cmp;

	base = NULL;
	base = stack;
	tmp = NULL;
	cmp = NULL;
	while (base->next)
	{
		cmp = base;
		tmp = base->next;
		while (tmp)
		{
			if (cmp->content < tmp->content)
				cmp = tmp;
			tmp = tmp->next;
		}
		ft_lstswp(base, cmp);
		base = base->next;
	}
	return (stack);
}
