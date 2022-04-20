/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtorrado <mtorrado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 20:02:07 by mtorrado          #+#    #+#             */
/*   Updated: 2021/04/07 20:47:48 by mtorrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = ft_strlen(dst);
	j = ft_strlen(src);
	if (size == 0)
		return (j);
	if (size < i)
		return (size + j);
	else
	{
		k = 0;
		while (((k + i) < size - 1) && src[k] != '\0')
		{
			dst[i + k] = src[k];
			k++;
		}
		dst[i + k] = '\0';
		return (i + j);
	}
}
