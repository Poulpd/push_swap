/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:03:33 by damohen           #+#    #+#             */
/*   Updated: 2024/11/25 13:07:52 by damohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	p;

	p = ft_strlen(s);
	while (p >= 0)
	{
		if (s[p] == (unsigned char)c) 
			return ((char *)s + p);
		p--;
	}
	return (NULL);
}
