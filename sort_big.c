/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperegri <cperegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 00:07:43 by cperegri          #+#    #+#             */
/*   Updated: 2022/03/19 16:20:59 by cperegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_min_and_max(t_list *a, t_data *data)
{
	int		j;

	j = 0;
	data->max = a->content;
	data->min = a->content;
	while (j < data->len_a)
	{
		if (a->content > data->max)
			data->max = a->content;
		if (a->content < data->min)
			data->min = a->content;
		a = a->next;
		j++;
	}
}

static void	push_middle(t_list **a, t_list **b, t_data *data)
{
	int	i;

	i = data->len_a - 2;
	while (i)
	{
		if (((*a)->content != data->max) && ((*a)->content != data->min))
		{
			push_b(a, b, &data->len_a, &data->len_b);
			i--;
		}
		else
			rotate_a(a);
	}
}

static int	set_move_amount_a(t_list *a, int i, int l)
{
	int		j;

	j = 0;
	while (a->next)
	{
		if ((a->content < l) && (a->next->content > l))
		{
			if (j < (i - j))
				return (j);
			else
				return (i - j);
		}
		else
			a = a->next;
		j++;
	}
	if ((a->content < l) && (a->next->content > l))
	{
		if (j < (i - j))
			return (j);
		else
			return (i - j);
	}
	return (100500);
}

static void	set_move_amount(t_list *a, t_list *b, t_data data)
{
	int		i;
	int		j;

	i = data.len_b;
	j = 0;
	while (j < i)
	{
		if (j < (i - j))
			b->move_amount = j;
		else
			b->move_amount = i - j;
		b->move_amount += set_move_amount_a(a, data.len_a, b->content);
		j++;
		if (b-> next)
			b = b->next;
	}
}

void	sort_big(t_list **a, t_list **b, t_data *data)
{
	get_min_and_max(*a, data);
	push_middle(a, b, data);
	while (data->len_b)
	{
		set_move_amount(*a, *b, *data);
		pick_and_push(a, b, data);
	}
	final_rotate(a, *data);
}
