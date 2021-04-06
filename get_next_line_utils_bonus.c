/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanoel- <mmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:55:34 by mmanoel-          #+#    #+#             */
/*   Updated: 2021/04/04 19:47:05 by mmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strdup(const char *s)
{
	char	*dup;
	int		c;
	int		len;

	c = 0;
	len = 0;
	while (s[len] != '\0')
		len++;
	dup = (char *)malloc(sizeof(*s) * (len + 1));
	if (s == NULL || dup == NULL)
		return (NULL);
	while (s[c] != '\0')
	{
		dup[c] = s[c];
		c++;
	}
	dup[c] = '\0';
	return (dup);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	c;
	size_t	cc;
	char	*substr;

	c = 0;
	cc = 0;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (substr == NULL)
		return (NULL);
	substr[len] = '\0';
	while (s[c] != '\0')
	{
		if (c >= start && cc < len)
		{
			substr[cc] = s[c];
			cc++;
		}
		c++;
	}
	return (substr);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		c;
	char	*dest;
	int		a;

	c = 0;
	a = 0;
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dest == NULL)
		return (NULL);
	while (s1[c] != '\0')
	{
		dest[c] = s1[c];
		c++;
	}
	while (s2[a] != '\0')
	{
		dest[c + a] = s2[a];
		a++;
	}
	dest[c + a] = '\0';
	return (dest);
}

char		*ft_strchr(const char *str, int c)
{
	char	*string;
	int		str_len;
	int		cont;

	string = (char *)str;
	str_len = ft_strlen(str);
	cont = 0;
	while (cont <= str_len)
	{
		if (string[cont] == c)
			return (&string[cont]);
		else
			cont++;
	}
	return (NULL);
}

void		ft_strdel(char **as)
{
	if (as != NULL && *as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}
