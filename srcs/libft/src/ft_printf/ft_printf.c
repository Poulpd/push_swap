/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 10:53:51 by damohen           #+#    #+#             */
/*   Updated: 2024/12/31 13:07:07 by damohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/ft_printf.h"

int	print_format(va_list ap, char specifier)
{
	char	*ptr;

	if (specifier == '%')
		return (ft_putchar('%'));
	if (specifier == 'c')
		return (ft_putchar(va_arg(ap, int)));
	if (specifier == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (specifier == 'i' || specifier == 'd')
		return (ft_putnbr(va_arg(ap, int)));
	if (specifier == 'u')
		return (ft_pbase(va_arg(ap, unsigned int), "0123456789"));
	if (specifier == 'x')
		return (ft_pbase(va_arg(ap, unsigned int), "0123456789abcdef"));
	if (specifier == 'X')
		return (ft_pbase(va_arg(ap, unsigned int), "0123456789ABCDEF"));
	if (specifier == 'p')
	{
		ptr = va_arg(ap, void *);
		if (!ptr)
			return (write(1, "(nil)", 5));
		return (write(1, "0x", 2), 2 + ft_pbase((unsigned long)ptr,
				"0123456789abcdef"));
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int		i;

	if (!format)
		return (-1);
	va_start(ap, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && !format[i + 1])
			break ;
		if (format[i] == '%')
		{
			count += print_format(ap, format[i + 1]);
			i++;
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
