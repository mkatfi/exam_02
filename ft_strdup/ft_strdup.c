/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 00:01:08 by mkatfi            #+#    #+#             */
/*   Updated: 2023/03/20 00:35:47 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include <string.h>

int  ft_strlen(char *str)
{
    int i;
    i = 0;
    while(str[i])
        i++;
    return(i);
}

char *ft_strdup(char *src)
{
    char *dsc;
    int i;

    i = 0;
    dsc = malloc (sizeof (char)* (ft_strlen(src) + 1));
    if (!dsc)
    {
        return (NULL);
    }

    while(src[i])
    {
        dsc[i] = src[i];
        i++;
    }
    dsc[i] ='\0';
    return (dsc); 
}