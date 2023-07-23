/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 01:38:26 by mkatfi            #+#    #+#             */
/*   Updated: 2023/04/08 01:42:39 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_atoi(const char* str)
{
    int i;
    int a;
    int nb;

    i = 0;
    a = 1;
    nb = 0;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            a *= (-1);
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        nb = nb * 10 + (str[i] - '0');
        i++;
    }
    return(nb * a);
}