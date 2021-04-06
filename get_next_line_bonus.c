/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanoel- <mmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 13:47:41 by mmanoel-          #+#    #+#             */
/*   Updated: 2021/04/04 20:08:57 by mmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t			ft_strlen(const char *str)
{
	int			len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

static int		nl(char **new_str, char **line)
{
	int			len;
	char		*temp;

	len = 0;
	while ((*new_str)[len] != '\n' && (*new_str)[len] != '\0')
		len++;
	if ((*new_str)[len] == '\n')
	{
		*line = ft_substr(*new_str, 0, len);
		temp = ft_strdup(&((*new_str)[len + 1]));
		free(*new_str);
		*new_str = temp;
		if ((*new_str)[0] == '\0')
			ft_strdel(new_str);
		return (1);
	}
	else
	{
		*line = ft_strdup(*new_str);
		ft_strdel(new_str);
		return (0);
	}
}

static int		validation(int fd, char **line, char **str, int r)
{
	if (r < 0)
		return (-1);
	else if (r == 0 && str[fd] == NULL)
	{
		*line = ft_strdup("");
		return (0);
	}
	else
		return (nl(&str[fd], line));
}

int				get_next_line(int fd, char **line)
{
	char		*buff;
	char		*temp;
	static char	*str[128];
	int			r;

	if (fd < 0 || fd >= 128 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while ((r = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[r] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(str[fd], buff);
			free(str[fd]);
			str[fd] = temp;
		}
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	free(buff);
	return (validation(fd, line, str, r));
}
