/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperegri <cperegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 00:24:16 by cperegri          #+#    #+#             */
/*   Updated: 2022/03/15 21:24:27 by cperegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	final_fantasy(t_list *a, t_data data)
{
	int	i;

	i = 0;
	while (a->content != data.min)
	{
		a = a->next;
		i++;
	}
	return (i);
}

void	final_rotate(t_list **a, t_data data)
{
	int	n;

	n = final_fantasy(*a, data);
	if (n <= data.len_a / 2)
	{
		while (n--)
			rotate_a(a);
	}
	else
	{
		while (data.len_a - n++)
			rev_rotate_a(a);
	}
}
