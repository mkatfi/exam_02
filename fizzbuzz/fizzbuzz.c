/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 14:00:04 by mkatfi            #+#    #+#             */
/*   Updated: 2023/04/09 14:20:15 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int ft_putnbr(int n)
{
    char* str = "0123456789";
    if (n >= 10)
        ft_putnbr(n / 10);
    write(1, &str[n % 10], 1);
    return(n);
}
int main(int ac, char** av)
{
    int i;

    (void)ac;
    i = 0;
 
    while (++i <= 100)
    {
        if ((i % 5 == 0) && (i % 3 == 0))
            write(1, "fizzbuzz\n", 9);
        else if (i % 3 == 0)
            write(1, "fizz\n", 5);
        else if (i % 5 == 0)
            write(1, "buzz\n", 5);
        else
        {
            ft_putnbr(i);
            write(1, "\n", 1);
        }
    }
}