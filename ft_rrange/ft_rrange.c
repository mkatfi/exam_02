/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:08:28 by mkatfi            #+#    #+#             */
/*   Updated: 2023/04/09 16:57:07 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int* ft_rrange(int start, int end)
{
    int i;
    int n = end - start + 1;
    int* k = malloc(sizeof(int) * n);
    i = 0;
    while (k && i < n)
    {
        k[i] = end;
        end--;
        i++;
    }
    return(k);
}