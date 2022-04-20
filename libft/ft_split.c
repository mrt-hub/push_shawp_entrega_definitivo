/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtorrado <mtorrado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:41:10 by mtorrado          #+#    #+#             */
/*   Updated: 2021/04/07 20:01:07 by mtorrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_reserve_list(const char *s, char c)
{
	int		words;
	int		i;
	char	**result;

	words = 0;
	i = 0;
	result = NULL;
	if (s)
	{
		while (s[i] != '\0')
		{
			if ((s[i] != c && i == 0) || (s[i] != c && s[i - 1] == c))
				words++;
			i++;
		}
		result = (char **)malloc(sizeof(char *) * (words + 1));
		if (!result)
			result = NULL;
	}
	return (result);
}

static int	ft_get_word_len(const char *s, char c, int i)
{
	int		j;

	j = i;
	while (s[j] != '\0' && s[j] != c)
		j++;
	return (j);
}

char	**ft_split(const char *s, char c)
{
	int		words;
	int		i;
	int		j;
	char	**result;

	i = 0;
	words = 0;
	result = ft_reserve_list(s, c);
	if (!result)
		return (NULL);
	while (s[i] != '\0')
	{
		j = ft_get_word_len(s, c, i);
		if (j > i)
		{
			result[words] = (char *)malloc(sizeof(char) * (j - i + 1));
			ft_strlcpy(result[words++], s + i, j - i + 1);
			i = j - 1;
		}
		i++;
		result[words] = NULL;
	}
	if (s[0] == '\0')
		result[words] = NULL;
	return (result);
}
