/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtorrado <mtorrado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:01:48 by mtorrado          #+#    #+#             */
/*   Updated: 2022/04/21 01:38:54 by mtorrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_i(t_dlist **stack_b, t_dlist *stack_b_order)
{
	int		i;
	t_dlist	*temp;

	i = 0;
	temp = *stack_b;
	while (stack_b_order->content != temp->content)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

void	smart_rotate_b(t_dlist **stack_b, int i, int len_block)
{
	if (i >= (ft_dlstsize(*stack_b) - len_block))
		reverse_rotate(stack_b, 'b');
	else if (i < len_block)
		rotate(stack_b, 'b');
}

t_dlist	*get_stack_b_order(t_dlist **stack_b)
{
	t_dlist	*stack_b_order;

	stack_b_order = ft_lst_dup(*stack_b);
	stack_b_order = ft_lstsort_reverse(stack_b_order);
	return (stack_b_order);
}

void	order_list_a(t_dlist **a, t_dlist **b, int len_block)
{
	t_dlist	*b_or;
	int		i;

	b_or = get_stack_b_order(b);
	while (*b)
	{
		i = get_i(b, b_or);
		if ((*b)->content == b_or->content)
		{
			push(b, a, 'b');
			if (ft_dlstsize(*b) > 1 && (*a)->next != NULL && ((*a)->content > (*a)->next->content)
				&& ((*b)->next != NULL && (*b)->content < (*b)->next->content))
				swap_ss(*a, *b);
			else if ((*a)->next != NULL && (*a)->content > (*a)->next->content)
				ft_swap(&((*a)->content), &((*a)->next->content), 'a');
			free_stack(&b_or);
			b_or = get_stack_b_order(b);
		}
		else if (b_or->next != NULL && (*b)->content == b_or->next->content)
			push(b, a, 'b');
		else
			smart_rotate_b(b, i, len_block);
	}
	free_stack(&b_or);
}
