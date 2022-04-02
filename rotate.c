/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperegri <cperegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:23:35 by cperegri          #+#    #+#             */
/*   Updated: 2022/03/23 13:28:25 by cperegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **a)
{
	*a = (*a)->next;
	return ;
}

void	rotate_a(t_list **a)
{
	if (*a)
	{
		rotate (a);
		write(1, "ra\n", 3);
	}
	return ;
}

void	rotate_b(t_list **b)
{
	if (*b)
	{
		rotate (b);
		write(1, "rb\n", 3);
	}
	return ;
}

void	rotate_r(t_list **a, t_list **b)
{
	if (*a && *b)
	{
		rotate(a);
		rotate(b);
		write(1, "rr\n", 3);
	}
	return ;
}
