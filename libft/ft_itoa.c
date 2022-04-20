/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtorrado <mtorrado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 18:46:56 by mtorrado          #+#    #+#             */
/*   Updated: 2021/04/06 17:42:42 by mtorrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ft_len(long int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	if (n < 0)
	{
		n = n * (-1);
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_get_number(char *result, int i, long num)
{
	while (num > 0)
	{
		result[i] = 48 + (num % 10);
		num = num / 10;
		i--;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;
	long	num;
	int		i;

	num = n;
	len = ft_len(num);
	result = (char *)malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	if (num == 0)
		result[0] = '0';
	if (num < 0)
	{
		result[0] = '-';
		num = num * -1;
	}
	i = len - 1;
	result = ft_get_number(result, i, num);
	result[len] = '\0';
	return (result);
}
