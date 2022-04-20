/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtorrado <mtorrado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 12:13:38 by mtorrado          #+#    #+#             */
/*   Updated: 2022/04/20 18:35:06 by mtorrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_len_block(int len)
{
	if (len >= 500)
		return (62);
	else if (len >= 100 && len < 500)
		return (20);
	else if (len > 5)
		return (5);
	else if (len == 4)
		return (2);
	return (0);
}

void	push_swap(t_dlist **stack_order, t_dlist **stack_a, t_dlist **stack_b)
{
	int	len_inic;

	len_inic = ft_dlstsize(*stack_order);
	if (len_inic == 2)
	{
		if (((*stack_a)->content) > ((*stack_a)->next->content))
			ft_swap(&((*stack_a)->content), &((*stack_a)->next->content), 'a');
	}
	if (len_inic <= 3)
		sort_3(stack_a);
	else if (len_inic <= 5)
	{
		mini_quick_sort(stack_a, stack_b, stack_order);
	}
	if (len_inic > 5)
	{
		quick_sort(stack_order, stack_a, stack_b, ft_get_len_block(len_inic));
		order_list_a(stack_a, stack_b, ft_get_len_block(len_inic));
	}
	free_stack(stack_order);
}

int	main(int argc, char **argv)
{
	char		**split_arg;
	t_dlist		*stack_a;
	t_dlist		*stack_b;
	t_dlist		*stack_order;

	split_arg = NULL;
	stack_a = NULL;
	stack_b = NULL;
	stack_order = NULL;
	if (argc > 1)
	{
		if (argc == 2)
			split_arg = ft_split(argv[1], ' ');
		else if (argc > 2)
			split_arg = &argv[1];
		stack_a = fill_list(&stack_a, split_arg);
		check_argv(&stack_a);
		stack_order = ft_lst_dup(stack_a);
		stack_order = ft_lstsort(stack_order);
		push_swap(&stack_order, &stack_a, &stack_b);
		free_stack (&stack_order);
	}
	free_stack (&stack_a);
	return (0);
}
