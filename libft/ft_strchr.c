/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtorrado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 19:06:58 by mtorrado          #+#    #+#             */
/*   Updated: 2021/03/26 19:29:48 by mtorrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*s1;
	unsigned int	i;

	i = 0;
	s1 = (char *)s;
	while (s1[i] != '\0')
	{
		if (s1[i] == (unsigned char)c)
		{
			return (s1 + i);
		}
		i++;
	}
	if (s1[i] == '\0' && (unsigned char)c == '\0')
		return (s1 + i);
	else
		return (NULL);
}
