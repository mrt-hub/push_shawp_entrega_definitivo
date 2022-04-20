/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtorrado <mtorrado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 20:25:30 by mtorrado          #+#    #+#             */
/*   Updated: 2021/04/06 19:49:57 by mtorrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int	i;
	char			*ret;

	i = 0;
	ret = NULL;
	while ((i < n) && (((unsigned char *)src)[i] != (unsigned char)c))
	{
		((char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	if (((unsigned char *)src)[i] == (unsigned char)c)
	{
		((char *)dest)[i] = ((char *)src)[i];
		ret = &((char *)dest)[i + 1];
		return (ret);
	}
	return (ret);
}
