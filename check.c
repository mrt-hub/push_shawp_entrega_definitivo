/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtorrado <mtorrado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 23:24:15 by mtorrado          #+#    #+#             */
/*   Updated: 2022/04/19 18:32:55 by mtorrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dup_list(t_dlist **stack)
{
	t_dlist	*temp;
	t_dlist	*temp2;

	temp = *stack;
	while (temp->next)
	{
		temp2 = *stack;
		while (temp2)
		{
			if (temp == temp2)
				temp2 = temp2->next;
			if (temp->content == temp2->content)
				ft_exit_error("Error\n", 1);
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
	return (0);
}

void	check_argv(t_dlist **stack)
{
	if (check_list_order(stack) == 1)
		ft_exit_error("", 0);
	check_dup_list(stack);
}
