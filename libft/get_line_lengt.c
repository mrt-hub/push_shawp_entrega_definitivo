/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line_lengt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtorrado <mtorrado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:22:24 by mtorrado          #+#    #+#             */
/*   Updated: 2021/11/24 20:01:56 by mtorrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_get_line_length(int fd)
{
	int		line_length;
	char	buffer[1];
	int		r;

	r = 1;
	line_length = 0;
	buffer[0] = '\0';
	while (r == 1)
	{
		r = read(fd, buffer, 1);
		if (buffer[0] != '\n')
			line_length++;
		else
			break ;
	}
	return (line_length);
}
