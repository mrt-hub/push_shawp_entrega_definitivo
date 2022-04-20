/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtorrado <mtorrado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:05:39 by mtorrado          #+#    #+#             */
/*   Updated: 2021/11/24 20:06:05 by mtorrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc2(size_t nmemb, size_t size)
{
	void	*rslt;
	int		sizemax;

	sizemax = nmemb * size;
	if (sizemax == 0)
		return (NULL);
	rslt = malloc(sizemax);
	if (rslt == NULL)
		return (NULL);
	ft_bzero(rslt, sizemax);
	return (rslt);
}
