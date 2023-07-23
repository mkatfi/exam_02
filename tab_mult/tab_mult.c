/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 11:15:48 by mkatfi            #+#    #+#             */
/*   Updated: 2023/04/09 11:55:51 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int ft_atoi(char* s)
{
    int i;
    int k;

    i = 0;
    k = 0;
    while (s[i] && (s[i] >= '0' && s[i] <= '9'))
    {
        k = k * 10 + (s[i] - '0');
        i++;
    }
    return (k);
}
int putnbr(int n)
{
    char* str = "0123456789abcdef";
    if (n >= 10)
        putnbr(n/10);
    write(1, &str[n % 10], 1);
    return(n);
}
int main(int ac, char** av)
{
    int i;
    int nb;

    if (ac == 2)
    {
        nb = ft_atoi(av[1]);
        i = 1;
        while (i <= 9)
        {
            putnbr(i);
            write(1, " x ", 3);
            putnbr(nb);
            write(1, " = ", 3);
            putnbr(nb * i);
            write(1, "\n", 1);
            i++;
        }
        return(0);
    }
    write(1, "\n", 1);
    return(0);
}