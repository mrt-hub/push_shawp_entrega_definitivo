/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtorrado <mtorrado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 20:46:33 by mtorrado          #+#    #+#             */
/*   Updated: 2021/04/07 20:49:51 by mtorrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_end(const char *s, const char *set)
{
	int	i;

	i = ft_strlen(s) - 1;
	if (i != -1)
	{
		while (i > 0 && ft_strchr(set, s[i]))
			i--;
	}
	return (i);
}

char	*ft_strtrim(const char *s, const char *set)
{
	char			*result;
	unsigned int	size;
	char			*start;
	char			*end;
	int				i;

	i = 0;
	if (!set || !s)
		return (NULL);
	if (!set)
		return ((char *)s);
	while (s[i] && ft_strchr(set, s[i]))
		i++;
	start = (char *)&s[i];
	i = ft_get_end(s, set);
	end = (char *)&s[i];
	if (end == start || i == 0 || !*s)
		size = 1;
	else
		size = end - start + 2;
	result = (char *)malloc (sizeof(char) * size);
	if (result)
		ft_strlcpy (result, start, size);
	return (result);
}
