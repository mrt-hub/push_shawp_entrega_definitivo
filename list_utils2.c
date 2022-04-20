/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtorrado <mtorrado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:32:01 by mtorrado          #+#    #+#             */
/*   Updated: 2022/04/20 18:31:24 by mtorrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_dlist **stack)
{
	t_dlist	*temp;

	if (*stack)
	{
		while (*stack)
		{
			temp = (*stack)->next;
			free(*stack);
			*stack = NULL;
			(*stack) = temp;
		}
		free(*stack);
		*stack = NULL;
	}
}

int	get_first_pos(t_dlist *stack, t_dlist *stack_a_order)
{
	int		i;
	t_dlist	*temp;

	temp = stack;
	i = 0;
	while (temp->content < stack_a_order->content)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

int	get_last_pos(t_dlist *stack, t_dlist *stack_a_order)
{
	int		i;
	int		ret;
	t_dlist	*temp;

	temp = stack;
	ret = 0;
	i = 0;
	while (temp)
	{
		if (temp->content < stack_a_order->content)
			ret = i;
		i++;
		temp = temp->next;
	}
	return (ret);
}

int	check_list_order(t_dlist **stack)
{
	t_dlist	*temp;
	int		i;

	i = 0;
	temp = *stack;
	while (temp->next)
	{
		if (temp->content < temp->next->content)
			i++;
		else
			break ;
		temp = temp->next;
	}
	if (temp->next == NULL)
		return (1);
	return (0);
}

void	print_stacks(t_dlist *stack_a, t_dlist *stack_b)
{
	t_dlist		*temp;
	int			num;
	t_dlist		*temp2;
	int			num2;

	temp = stack_a;
	while (temp)
	{
		num = temp->content;
		printf("num stack a: %d\n", num);
		temp = temp->next;
	}
	printf("\n");
	temp2 = stack_b;
	while (temp2 != NULL)
	{
		num2 = temp2->content;
		printf("num stack b: %d\n", num2);
		temp2 = temp2->next;
	}
}
