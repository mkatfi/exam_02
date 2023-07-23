/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:01:35 by mkatfi            #+#    #+#             */
/*   Updated: 2023/07/03 14:22:19 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<unistd.h>
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 3
#endif

int ft_strlen(char* s)
{
    int i;

    i = 0;
    if (!s)
        return(0);
    while (s[i])
        i++;
    return(i);
}
int ft_strchar(char* c)
{
    int i;
    i = 0;
    if (!c)
        return(0);
    while (c[i])
        if (c[i++] == '\n')
            return(1);
    return(0);
}
char* ft_strjoin(char* s1, char* s2)
{
    int i;
    int j;
    char* g;

    g = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
    if (!g)
    {
        free(s1);
        return(NULL);
    }
    i = 0;
    while (s1 && s1[i])
    {
        g[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2 && s2[j])
        g[i++] = s2[j++];
    g[i] = '\0';
    free(s1);
    return(g);
}
char	*ft_line(char *s)
{
	int		i;
	char	*p;

	i = 0;
	if (!s || s[i] == '\0')
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	p = malloc(sizeof(char) * (i + 2));
	if (!p)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		p[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		p[i++] = '\n';
	p[i] = '\0';
	return (p);
}

char	*ft_cha(char *s)
{
	int		i;
	int		j;
	char	*k;

	i = 0;
	while (s && s[i] && s[i] != '\n')
		i++;
	if (!s || s[i] == '\0')
	{
		free(s);
		return (NULL);
	}
	k = malloc (sizeof(char) * (ft_strlen(s) - i + 1));  
	if (!k)
	{
		free(s);
		return (NULL);
	}
	i++;
	j = 0;
	while (s[i])
		k[j++] = s[i++];
	k[j] = '\0';
	free(s);
	return (k);
}

char	*ft_read(int fd, char *container)
{
	char	*buff;
	int		i;

	i = 0;
    buff = malloc(BUFFER_SIZE + 1 * sizeof(char));
    while (buff[i])
    {
        buff[i] = 0;
        i++;
    }
    if (!buff)
        return (NULL);
    i = 1;
    while (ft_strchar(buff) == 0 && i != 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(buff);
			free(container);
			return (NULL);
		}
		buff[i] = '\0';
		container = ft_strjoin(container, buff);
	}
	free(buff);
	return (container);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*s;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s = ft_read(fd, s);
	line = ft_line(s);
	s = ft_cha(s);
	return (line);
}

