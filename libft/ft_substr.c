/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtorrado <mtorrado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 13:13:50 by mtorrado          #+#    #+#             */
/*   Updated: 2021/04/07 20:50:37 by mtorrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_getmem(const char *s, size_t len, unsigned int start)
{
	size_t	size;
	char	*result;

	size = ft_strlen(s);
	result = NULL;
	if (size < start)
	{
		result = (char *)malloc(sizeof(char) * 1);
		if (result)
		{
			result[0] = '\0';
			return (result);
		}
	}
	if (len > size)
		result = (char *)malloc(sizeof(char) * (size + 1));
	else
		result = (char *)malloc(sizeof(char) * (len + 1));
	return (result);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*result;
	unsigned int	i;
	size_t			size;

	i = 0;
	result = NULL;
	if (!s)
		return (NULL);
	size = ft_strlen(s);
	result = ft_getmem(s, len, start);
	if (result && size > start)
	{
		while (i < len && s[start + i] != '\0')
		{
			result[i] = s[start + i];
			i++;
		}
		result[i] = '\0';
	}
	return (result);
}
