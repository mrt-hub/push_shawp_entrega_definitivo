/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtorrado <mtorrado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:02:30 by mtorrado          #+#    #+#             */
/*   Updated: 2021/11/24 20:03:10 by mtorrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_write_conc(const char *s1, const char *s2, char	*result)
{
	int		i;
	int		j;

	i = ft_strlen(s1);
	j = 0;
	while (s1[j] != '\0')
	{
		result[j] = s1[j];
		j++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*result;
	int				j;
	int				i;

	result = NULL;
	if (s1 && s2)
	{
		i = ft_strlen(s1);
		j = ft_strlen(s2);
		result = (char *)malloc(sizeof(char) * (i + j + 1));
		j = 0;
		if (result)
			result = ft_write_conc(s1, s2, result);
	}
	return (result);
}
