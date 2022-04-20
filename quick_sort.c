/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtorrado <mtorrado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:36:22 by mtorrado          #+#    #+#             */
/*   Updated: 2022/04/20 19:15:58 by mtorrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort_b(t_dlist **stack_b, t_dlist *pivot_b)
{
	if (ft_dlstsize(*stack_b) >= 2)
	{
		if (ft_dlstsize(*stack_b) == 2)
		{
			if ((*stack_b)->content < (*stack_b)->next->content)
				rotate(stack_b, 'b');
		}
		if ((*stack_b)->content <= pivot_b->content)
			rotate(stack_b, 'b');
	}
}

void	smart_rotate(t_dlist **stack_a, t_dlist **stack_a_order)
{
	if (get_first_pos(*stack_a, *stack_a_order)
		<= (ft_dlstsize(*stack_a) - get_last_pos(*stack_a, *stack_a_order)))
		rotate(stack_a, 'a');
	else
		reverse_rotate(stack_a, 'a');
}

void	quick_sort_2(t_dlist **a_or, t_dlist **a, t_dlist **b, int len_block)
{
	int		cont;
	int		cont2;
	t_dlist	*pivot_b;
	t_dlist	*temp;

	cont = 0;
	cont2 = 0;
	temp = *a_or;
	while (++cont < len_block)
	{
		if (cont == len_block / 2)
			pivot_b = temp;
		temp = temp->next;
	}
	while (cont2 < len_block)
	{
		if ((*a)->content <= temp->content)
		{
			push(a, b, 'a');
			quick_sort_b(b, pivot_b);
			cont2++;
		}
		else
			smart_rotate(a, a_or);
	}
}

void	quick_sort(t_dlist **a_or, t_dlist **a, t_dlist **b, int len_block)
{
	quick_sort_2(a_or, a, b, len_block);
	free_stack(a_or);
	*a_or = ft_lst_dup(*a);
	*a_or = ft_lstsort(*a_or);
	if (ft_dlstsize(*a) > 2)
	{
		if (ft_dlstsize(*a_or) < len_block)
			len_block = ft_dlstsize(*a_or) - 1;
		quick_sort(a_or, a, b, len_block);
	}
}
