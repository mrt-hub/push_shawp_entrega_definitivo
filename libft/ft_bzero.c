/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtorrado <mtorrado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 18:24:24 by mtorrado          #+#    #+#             */
/*   Updated: 2021/11/22 22:32:56 by mtorrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*r;

	i = 0;
	r = (unsigned char *)s;
	while (i < n)
	{
		r[i] = 0;
		i++;
	}
	s = r;
}

/*void	ft_bzero(void *s, size_t n)
{
	size_t			count;
	unsigned char	*p;

	p = (unsigned char *)s;
	count = 0;
	while (count < n)
	{
		*p = 0;
		p++;
		count++;
	}
	return ;
}*/
