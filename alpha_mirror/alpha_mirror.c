/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 08:58:23 by mkatfi            #+#    #+#             */
/*   Updated: 2023/04/10 09:28:59 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int main(int ac, char** av)
{
    int i;
    i = 0;
    if (ac == 2)
    {
        while (av[1][i])
        {
            if (av[1][i] >= 'a' && av[1][i] <= 'z')
                av[1][i] = ('z' + 'a') - av[1][i];
            else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
                av[1][i] = ('Z' + 'A') - av[1][i];
            write(1, &av[1][i++], 1);
        }
    }
    write(1, "\n", 1);
}