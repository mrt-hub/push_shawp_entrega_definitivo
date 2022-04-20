/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtorrado <mtorrado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:52:02 by mtorrado          #+#    #+#             */
/*   Updated: 2022/04/19 19:49:31 by mtorrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_check_sig(int neg, int plus, long int ret)
{
	if (neg == 1 && plus == 0)
	{
		ret = (-1) * ret;
		return (ret);
	}
	if (neg > 1)
		ft_exit_error("Error\n", 1);
	if (plus > 1)
		ft_exit_error("Error\n", 1);
	if (plus >= 1 && neg >= 1)
		ft_exit_error("Error\n", 1);
	return (ret);
}

void	check_char(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] < '0' || s[i] > '9') && s[i] != ' '
			&& s[i] != '-' && s[i] != '+')
			ft_exit_error("Error\n", 1);
		i++;
	}
}

long int	ft_get_int(char *s, int i)
{
	long int	ret;

	ret = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		ret = 10 * ret + s[i] - '0';
		i++;
	}
	if (s[i] == '+' || s[i] == '-' || s[i] == ' ')
		ft_exit_error("Error\n", 1);
	return (ret);
}

long int	ft_int_atoi(char *s)
{
	int					i;
	int					neg;
	long int			ret;
	int					plus;

	ret = 0;
	neg = 0;
	plus = 0;
	check_char(s);
	i = 0;
	while (s[i] == ' ')
		i++;
	while (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			neg++;
		if (s[i] == '+')
			plus++;
		i++;
	}
	if (s[i] == '\0')
		ft_exit_error("Error\n", 1);
	ret = ft_get_int(s, i);
	ret = ft_check_sig(neg, plus, ret);
	return (ret);
}
