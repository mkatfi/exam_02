/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:00:44 by mkatfi            #+#    #+#             */
/*   Updated: 2023/04/09 18:04:55 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include<unistd.h>

t_list *sort_list(t_list* lst, int (*cmp)(int, int))
{
    t_list* tmp;
    tmp = lst;
    int swap;

    while (lst->next != NULL)
    {
        if (cmp(lst->data, lst->next->data) == 0)
        {
            swap = lst->data;
            lst->data = lst->next->data;
            lst->next->data = swap;
            lst = tmp;
        }
        else
           lst = lst->next;
    }
    lst = tmp;
    return(lst);
}