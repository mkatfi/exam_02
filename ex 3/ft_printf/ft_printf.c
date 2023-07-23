/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkatfi <mkatfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 17:23:21 by mkatfi            #+#    #+#             */
/*   Updated: 2023/07/03 14:15:17 by mkatfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int ft_putchar(char c)
{
    return(write(1, &c, 1));
}
int ft_hexa(unsigned int n)
{
    int i;

    i = 0;
    if (n > 16)
        i += ft_hexa(n / 16);
    i += write(1, &"0123456789abcdef"[n % 16], 1);
    return(i);
}

int ft_putnbr(int nb)
{
    int i;

    i = 0;
    if (nb == -2147483648)
        return(write(1, &"-2147483648", 11));
    if (nb < 0)
    {
        i += ft_putchar('-');
        nb *= -1;
    }
    if (nb > 10)
        i += ft_putnbr(nb / 10);
    i += write(1, &"0123456789"[nb % 10], 1);
    return(i);
}

int ft_putstr(char* s)
{
    int i;
    i = 0;
    if (s == NULL)
        return(ft_putstr("(null)"));
    while (s[i])
        write(1, &s[i++], 1);
    return(i);
}

int ft_cheak(char h, va_list p)
{
    int i;

    i = 0;
    if (h == 's')
        i += ft_putstr(va_arg(p, char*));
    else if (h == 'd')
        i += ft_putnbr(va_arg(p, int));
    else if (h == 'x')
        i += ft_hexa(va_arg(p, unsigned int));
    else
        i += ft_putchar(h);
    return(i);
}
int ft_printf(const char* str, ...)
{
    int i;
    int j;
    va_list p;
    va_start(p, str);

    i = 0;
    j = 0;
    while (str[i])
    {
        if (str[i] == '%')
        {
            j += ft_cheak(str[i + 1], p);
            i+=2;
        }
        else if (str[i] == '%' && str[i + 1] == '%')
            j += write(1, &str[i + 1], 1);
        else
            j += ft_putchar(str[i++]);
    }
    va_end(p);
    return(j);
}
