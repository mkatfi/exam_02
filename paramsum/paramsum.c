/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 18:17:01 by mkatfi            #+#    #+#             */
/*   Updated: 2023/04/09 18:34:33 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
int ft_putnbr(int n)
{
    char* s = "0123456789";
    if (n >= 10)
        ft_putnbr(n / 10);
    write(1, &s[n % 10], 1);
    return(n);
}

int main(int ac, char** av)
{
    int i;
    (void)av;
    i = ac - 1;
    ft_putnbr(i);
    write(1, "\n", 1);
}