/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtorrado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 20:44:16 by mtorrado          #+#    #+#             */
/*   Updated: 2021/03/29 17:52:32 by mtorrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dst;
	char		*srcc;

	dst = (char *)dest;
	srcc = (char *)src;
	if (dst > srcc)
	{
		while (n--)
			dst[n] = srcc[n];
	}
	else if (dst < srcc)
		ft_memcpy(dst, srcc, n);
	dest = (void *)dst;
	return (dest);
}
