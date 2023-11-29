/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 05:46:52 by viniferr          #+#    #+#             */
/*   Updated: 2023/11/29 05:48:12 by viniferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf_arg(const char *fmt, int i, va_list ap)
{
    if (fmt[i + 1] == '%')
        return (ft_putchar(fmt[i + 1]));
    else if (fmt[i + 1] == 'c')
        return (ft_putchar(va_arg(ap, int)));
    else if (fmt[i + 1] == 's')
        return (ft_putstr(va_arg(ap, char *)));
    else if (fmt[i + 1] == 'd' || fmt[i + 1] == 'i')
        return (ft_putnbr(va_arg(ap, int)));
    else if (fmt[i + 1] == 'u')
        return (putnbr_u(va_arg(ap, unsigned int)));
    else if (fmt[i + 1] == 'x' || fmt[i + 1] == 'X')
    {
        if (fmt[i + 1] == 'X')
            return (put_hex(va_arg(ap, unsigned int), "0123456789ABCDEF"));
        else
            return (put_hex(va_arg(ap, unsigned int), "0123456789abcdef"));
    }
    else if (fmt[i + 1] == 'p')
        return (ft_putstr("0x") + put_pointer(va_arg(ap, void *), \
                "0123456789abcdef"));
    else
        return (0);
}

