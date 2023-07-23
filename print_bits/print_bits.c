/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:04:03 by mkatfi            #+#    #+#             */
/*   Updated: 2023/04/09 16:04:06 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	put_bits(unsigned char octet)
{
    char* str = "01";
    if (octet >= 2)
        put_bits(octet / 2);
    write(1, &str[octet % 2], 1);
    
}

void	print_bits(unsigned char octet)
{
    int i = 0;
    int b = 8;
    unsigned char  a = octet;
    while (a > 0)
    {
        a = a / 2;
        i++;
    }
    while (i < b)
    {
        write(1, "0", 1);
        b--;
    }
    put_bits(octet);
}