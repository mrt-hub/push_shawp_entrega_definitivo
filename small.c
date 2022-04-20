/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtorrado <mtorrado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 19:21:09 by mtorrado          #+#    #+#             */
/*   Updated: 2022/04/20 19:23:04 by mtorrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_dlist **a)
{
	if (check_list_order(a) == 0)
	{
		if (((*a)->content) > ((*a)->next->content)
			&& ((*a)->content) < ((*a)->next->next->content))
			ft_swap(&((*a)->content), &((*a)->next->content), 'a');
		else if (((*a)->content) > ((*a)->next->content))
		{
			rotate(a, 'a');
			if (check_list_order(a) == 0)
				ft_swap(&((*a)->content), &((*a)->next->content), 'a');
		}
		else
		{
			reverse_rotate(a, 'a');
			if (check_list_order(a) == 0)
				ft_swap(&((*a)->content), &((*a)->next->content), 'a');
		}
	}
}

void	mini_quick_sort(t_dlist **a, t_dlist **b, t_dlist **stack_order)
{
	int		i;
	t_dlist	*temp;

	temp = *stack_order;
	i = get_pos(stack_order, a);
	while (ft_dlstsize(*b) <= 1)
	{
		while ((*a)->content != temp->content)
		{
			if (i <= 3)
				rotate(a, 'a');
			else
				reverse_rotate(a, 'a');
		}
		push(a, b, 'a');
		temp = temp->next;
	}
	if (ft_dlstsize(*a) == 3)
		sort_3(a);
	if ((*b)->content < (*b)->next->content)
		ft_swap(&((*b)->content), &((*b)->next->content), 'b');
	if (ft_dlstsize(*a) == 2 && ((*a)->content > (*a)->next->content))
		ft_swap(&((*a)->content), &((*a)->next->content), 'b');
	while (ft_dlstsize(*b) > 0)
		push(b, a, 'b');
}
