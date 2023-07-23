/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 09:50:13 by mkatfi            #+#    #+#             */
/*   Updated: 2023/04/10 10:14:54 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int main(int ac, char** av)
{
    int i;
    int j;

    i = 1;
   
    while (av[i])
    {
        j = 0;
        while (av[i][j])
        {
            if (av[i][j] >= 'A' && av[i][j] <= 'Z')
                av[i][j] += 32;
            j++;
        }
        i++;
    }
    i = 1;
    while (av[i])
    {
        j = 0;
        while (av[i][j])
        {
            if (av[i][j + 1] == 32 || !av[i][j + 1])
            {
                if (av[i][j] >= 'a' && av[i][j] <= 'z')
                    av[i][j] -= 32;
            }
            write(1, &av[i][j], 1);
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
    if (ac == 1)
        write(1, "\n", 1);
}