/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperegri <cperegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:21:43 by cperegri          #+#    #+#             */
/*   Updated: 2022/03/15 20:16:55 by cperegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int	*a, int	*b)
{
	if (*a != *b)
	{
		*a += *b;
		*b = *a - *b;
		*a -= *b;
	}
}

void	swap_a(t_list *a)
{
	write(1, "sa\n", 3);
	swap(&a->content, &a->next->content);
	return ;
}

void	swap_b(t_list *b)
{
	write(1, "sb\n", 3);
	swap(&b->content, &b->next->content);
	return ;
}

void	swap_ss(t_list *a, t_list *b)
{
	swap(&a->content, &a->next->content);
	swap(&b->content, &b->next->content);
	write(1, "ss\n", 3);
	return ;
}
