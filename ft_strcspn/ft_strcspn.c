/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 01:32:53 by mkatfi            #+#    #+#             */
/*   Updated: 2023/04/10 13:45:00 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>


size_t	ft_strcspn(const char* s, const char* reject)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (s[i])
    {
        while (reject[j])
        {
            if (reject[j] == s[i])
                return(i);
            j++;
        }
        j = 0;
        i++;
    }
    return(i);
}

