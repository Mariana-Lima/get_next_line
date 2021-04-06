/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanoel- <mmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 13:47:41 by mmanoel-          #+#    #+#             */
/*   Updated: 2021/04/04 12:24:46 by mmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	compare(char s1, char const *set)
{
	int		c;

	c = 0;
	while (set[c] != '\0')
	{
		if (s1 == set[c])
			return (1);
		else
			c++;
	}
	return (0);
}

char		*ft_strtrim(char *s1, char const *set)
{
	int		len;
	int		len2;

	len = 0;
	len2 = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (s1[len] != '\0' && compare(s1[len], set))
		len++;
	while (s1[len2] != '\0')
		len2++;
	if (len2 > 0)
		len2--;
	while (len2 > len && compare(s1[len2], set))
		len2--;
	return (ft_substr(s1, len, len2 - len + 1));
}

// int read_line()
// {
// 	return(1);
// }

int get_next_line(int fd, char **line)
{
	int *cont;
	char *nl;

	//cont = ft_strlen(fd);
	cont = 0;
	nl = "'\n'";
	if(fd < 0|| !line || BUFFER_SIZE <= 0)
		return (-1);

	while(fd[cont] != '\0')
	{
		*ft_strtrim(*line, nl);
		cont ++;
	}
	return(0);
}
/*
o strtrim remove do inicio e do fim o caracter espercificado no segundo parâmetro
ideia: usar ele para identificar o \n e retirá-lo
para isso preciso ir copiando os arquivos que já foram lidos para uma variável
	para isso consigo usar uma função auxiliar: memcpy ou memmove, talvez(?)
preciso garantir que a verificação esteja correta
preciso ler corretamente cada palavra do arquivo de forma individual para fazer a comparação correta
*/
/* outra ideia: verificar se é printável, se sim copia, se não ignora*/