/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 10:39:22 by mkatfi            #+#    #+#             */
/*   Updated: 2023/04/10 11:02:09 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int digit(int n)
{
    int i;

    i = 0;
    if (n <= 0)
    {
        n *= (-1);
        i++;
    }
    while (n != 0)
    {
        n = n / 10;
        i++;
    }
    return(i);
}

char* ft_itoa(int nbr)
{
    char* p;
    int i;
  

    i = digit(nbr);
    p = malloc(sizeof(char) * i + 1);
    if (!p)
        return(NULL);
    p[i] = '\0';
    i--;
    if (nbr == 0)
        p[0] = 48;
    if (nbr < 0)
    {
        nbr *= (-1);
        p[0] = '-';
    }
    while (nbr != 0)
    {
        p[i] = nbr % 10 + 48;
        nbr = nbr / 10;
        i--;
    }
    return(p);
}