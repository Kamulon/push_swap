/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperegri <cperegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:24:10 by cperegri          #+#    #+#             */
/*   Updated: 2022/03/15 20:16:30 by cperegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_list **a)
{
	*a = (*a)->prev;
	return ;
}

void	rev_rotate_a(t_list **a)
{
	rev_rotate (a);
	write(1, "rra\n", 4);
	return ;
}

void	rev_rotate_b(t_list **b)
{
	rev_rotate (b);
	write(1, "rrb\n", 4);
	return ;
}

void	rev_rotate_r(t_list **a, t_list **b)
{
	rev_rotate(a);
	rev_rotate(b);
	write(1, "rrr\n", 4);
	return ;
}
