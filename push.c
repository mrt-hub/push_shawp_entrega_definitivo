/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtorrado <mtorrado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 00:38:22 by mtorrado          #+#    #+#             */
/*   Updated: 2022/04/20 18:35:49 by mtorrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_dlist **stack, t_dlist **stack_dest, char c)
{
	if (stack_dest)
		ft_dlstadd_front(stack_dest, ft_dlstnew((*stack)->content));
	else
		*stack_dest = ft_dlstnew((*stack)->content);
	del_first_node_lst(stack);
	if (c == 'a')
		write(1, "pb\n", 3);
	if (c == 'b')
		write(1, "pa\n", 3);
}
