/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 21:38:35 by lamasson          #+#    #+#             */
/*   Updated: 2022/11/18 14:50:50 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif
# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(char *s);
int		ft_check(char *str);
char	*get_next_line(int fd);

#endif
