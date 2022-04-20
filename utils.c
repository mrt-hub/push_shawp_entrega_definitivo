/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtorrado <mtorrado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 23:28:17 by mtorrado          #+#    #+#             */
/*   Updated: 2022/04/20 19:26:37 by mtorrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del_first_node_lst(t_dlist **stack)
{
	t_dlist	*temp;

	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}

void	ft_exit_error(char *msg, int error)
{
	if (error != 0)
		ft_putstr_fd(msg, 2);
	exit(error);
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] || s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
		{
			if (s1[i] > s2[i])
				return (1);
			else
				return (-1);
		}
	}
	return (0);
}

int	get_pos(t_dlist **stack_order, t_dlist **stack)
{
	t_dlist	*temp;
	t_dlist	*stack_temp;
	int		i;

	i = 0;
	temp = *stack_order;
	stack_temp = *stack;
	while ((stack_temp)->content != temp->content)
	{
		stack_temp = stack_temp->next;
		i++;
	}
	return (i);
}
