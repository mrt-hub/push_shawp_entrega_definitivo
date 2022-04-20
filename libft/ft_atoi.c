/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtorrado <mtorrado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 18:34:59 by mtorrado          #+#    #+#             */
/*   Updated: 2021/04/07 18:55:02 by mtorrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int	ft_check_range(long int res, const char *nptr, int sig, int i)
{
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (res > 922337203685477580 && nptr[i] > '7' && nptr[i] <= '9')
		{
			if (sig == 1)
				return (0);
			else
				return (-1);
		}
		else
		{
			res = res * 10 + (nptr[i] - '0');
			i++;
		}
	}
	if (sig == 1)
		res = (-1) * res;
	return (res);
}

int	ft_atoi(const char *nptr)
{
	int			i;
	long int	res;
	int			neg;

	i = 0;
	res = 0;
	neg = 0;
	while (nptr[i] == '\n' || nptr[i] == ' ' || nptr[i] == '\t'
		|| nptr[i] == '\f' || nptr[i] == '\r' || nptr[i] == '\v')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg++;
		i++;
	}
	res = ft_check_range(res, nptr, neg, i);
	return (res);
}
