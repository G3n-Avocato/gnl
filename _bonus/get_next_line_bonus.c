/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:31:18 by lamasson          #+#    #+#             */
/*   Updated: 2022/11/18 13:45:20 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_get_line(char *str)
{
	int		y;
	int		i;
	char	*line;

	y = 0;
	i = ft_check(str);
	if (i == 0)
		i = ft_strlen(str);
	line = malloc(sizeof(char) * (i + 1));
	while (y < i)
	{
		line[y] = str[y];
		y++;
	}
	line[y] = '\0';
	return (line);
}

static char	*ft_get_tmp(char *tmp)
{
	char	*new_tmp;
	int		i;
	int		j;
	int		k;

	k = 0;
	i = ft_check(tmp);
	j = ft_strlen(tmp);
	if (i == 0 || i == j)
	{
		free(tmp);
		return (NULL);
	}
	new_tmp = malloc(sizeof(char) * ((j - i) + 1));
	while (tmp[i] != '\0')
	{
		new_tmp[k] = tmp[i];
		k++;
		i++;
	}
	new_tmp[k] = '\0';
	free(tmp);
	return (new_tmp);
}

static void	ft_join(char *tmp, char *buf, char *s3)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (tmp && tmp[i] != '\0')
	{
		s3[i] = tmp[i];
		i++;
	}
	while (buf && buf[y] != '\0')
	{
		s3[i] = buf[y];
		i++;
		y++;
	}
	s3[i] = '\0';
}

static char	*ft_strjoin(char *tmp, char *buf)
{
	char	*s3;
	int		size_s3;

	size_s3 = ft_strlen(tmp) + ft_strlen(buf);
	s3 = malloc(sizeof(char) * (size_s3 + 1));
	ft_join(tmp, buf, s3);
	if (tmp)
		free(tmp);
	return (s3);
}

char	*get_next_line(int fd)
{
	static char	*tmp[1024];
	char		*line;
	char		*buf;
	int			i;

	i = 1;
	if (fd > 1024)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (i != 0 && ft_check(tmp[fd]) == 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == 0 || i == -1)
			break ;
		buf[i] = '\0';
		tmp[fd] = ft_strjoin(tmp[fd], buf);
	}
	free(buf);
	if (!tmp[fd])
		return (NULL);
	line = ft_get_line(tmp[fd]);
	tmp[fd] = ft_get_tmp(tmp[fd]);
	return (line);
}

/*
#include <fcntl.h>
#include <stdio.h>
int     main()
{
        int     fd;
        char    *str;
        char    buf[1];

        fd = open("gnl.txt", O_RDONLY);
        if (fd == -1)
                return (printf("error fd"));
        str = get_next_line(fd);
        while (str)
        {
                printf("%s", str);
                free(str);
                //read(0, buf, 1);
                str = get_next_line(fd);
        }
        str = get_next_line(fd);
        close(fd);
        str = get_next_line(fd);
        return (0);
}*/
