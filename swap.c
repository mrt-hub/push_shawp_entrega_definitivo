/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtorrado <mtorrado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 00:44:13 by mtorrado          #+#    #+#             */
/*   Updated: 2022/04/20 19:24:40 by mtorrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *content_a, int *content_b, char c)
{
	int	content;

	content = *content_a;
	*content_a = *content_b;
	*content_b = content;
	if (c == 'a')
		write(1, "sa\n", 3);
	if (c == 'b')
		write(1, "sb\n", 3);
	if (c == 'x')
		write(1, "ss\n", 3);
}

void	swap_stack(t_dlist *stack, char c)
{
	if (stack->next)
		ft_swap(&stack->content, &stack->next->content, c);
}

void	swap_ss(t_dlist *stack_a, t_dlist *stack_b)
{
	ft_swap(&stack_a->content, &stack_a->next->content, 'x');
	ft_swap(&stack_b->content, &stack_b->next->content, 'n');
}
