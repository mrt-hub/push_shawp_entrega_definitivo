/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtorrado <mtorrado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 00:06:14 by mtorrado          #+#    #+#             */
/*   Updated: 2022/04/20 19:18:09 by mtorrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_dlist **stack, char c)
{
	ft_dlstadd_back(stack, ft_dlstnew((*stack)->content));
	del_first_node_lst(stack);
	if (c == 'a')
		write(1, "ra\n", 3);
	if (c == 'b')
		write(1, "rb\n", 3);
}

void	rotate_rr(t_dlist **stack_a, t_dlist **stack_b)
{
	rotate(stack_a, 'r');
	rotate(stack_b, 'r');
	write(1, "rr\n", 3);
}

void	reverse_rotate(t_dlist **stack, char c)
{
	t_dlist	*temp;

	temp = *stack;
	while (temp->next->next != NULL)
		temp = temp->next;
	ft_dlstadd_front(stack, ft_dlstnew(temp->next->content));
	free(temp->next);
	temp->next = NULL;
	if (c == 'a')
		write(1, "rra\n", 4);
	if (c == 'b')
		write(1, "rrb\n", 4);
}

void	reverse_rotate_rr(t_dlist **stack_a, t_dlist **stack_b)
{
	reverse_rotate(stack_a, 'r');
	reverse_rotate(stack_b, 'r');
	write(1, "rrr\n", 4);
}
