/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_on_top.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:25:03 by damohen           #+#    #+#             */
/*   Updated: 2025/02/24 11:26:49 by damohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/push_swap.h"

static void	min_on_top(t_stack_node **a)
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}
