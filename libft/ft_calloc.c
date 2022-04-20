/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtorrado <mtorrado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 18:38:40 by mtorrado          #+#    #+#             */
/*   Updated: 2021/04/07 16:24:47 by mtorrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*result;

	i = 0;
	result = malloc(nmemb * size);
	if (result)
	{
		while (i < nmemb * size)
		{
			((char *)result)[i] = 0;
			i++;
		}
	}
	return (result);
}
