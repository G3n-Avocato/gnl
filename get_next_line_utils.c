/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:42:19 by lamasson          #+#    #+#             */
/*   Updated: 2022/11/18 14:53:27 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i] != '\0')
		i++;
	return (i);
}

int	ft_check(char *str)
{
	int		i;
	char	c;

	i = 0;
	c = '\n';
	if (!str)
		return (0);
	while (str[i] != c)
	{
		if (str[i] == '\0')
			return (0);
		i++;
	}
	return (i + 1);
}
