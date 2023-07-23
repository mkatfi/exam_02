/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 02:01:23 by mkatfi            #+#    #+#             */
/*   Updated: 2023/03/20 02:20:49 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int main(int ac, char** av)
{
    int i;
    int j;
    int k;

    i = 0;
    if (ac == 3)
    {
        while (av[1][i])
        {
            j = 0;
            while (av[2][j])
            {
                if (av[1][i] == av[2][j])
                {
                    k = 0;
                    while (av[1][k] != av[1][i])
                        k++;
                    if (k == i)
                    {
                        k = 0;
                        while (av[2][k] != av[2][j])
                            k++;
                        if (k == j)
                            write(1, &av[1][i], 1);
                    }
                }
                j++;
            }
            i++;
        }
    }
    write(1, "\n", 1);
}