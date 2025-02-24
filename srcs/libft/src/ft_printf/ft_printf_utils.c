/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 10:49:23 by damohen           #+#    #+#             */
/*   Updated: 2024/12/31 10:53:19 by damohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/ft_printf.h"
#include "../../inc/libft.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6), 6);
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	char		c;
	long int	len;
	long int	nb;

	nb = n;
	len = 0;
	if (nb < 0)
	{
		len += ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
	{
		len += ft_putnbr(nb / 10);
	}
	len++;
	c = (nb % 10) + '0';
	write(1, &c, 1);
	return (len);
}

int	ft_pbase(unsigned long int nb, char *base)
{
	unsigned long int	base_len;
	int					len;

	if (!base || !base[1])
		return (0);
	base_len = 0;
	len = 0;
	while (base[base_len])
		base_len++;
	if (nb >= base_len)
	{
		len += ft_pbase(nb / base_len, base);
	}
	len += ft_putchar(base[nb % base_len]);
	return (len);
}
