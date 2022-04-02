/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_and_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperegri <cperegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 00:20:08 by cperegri          #+#    #+#             */
/*   Updated: 2022/03/19 16:26:40 by cperegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_b_index(t_list *b, int len)
{
	int	i;
	int	i_save;
	int	min_index;

	i = 0;
	i_save = 0;
	min_index = b->move_amount;
	while (i < len)
	{
		if (b->move_amount < min_index)
		{
			min_index = b->move_amount;
			i_save = i;
		}
		b = b->next;
		i++;
	}
	return (i_save);
}

static int	get_a_index(t_list *a, int pick_content)
{
	int	i;

	i = 0;
	while (!(a->prev->content < pick_content && a->content > pick_content))
	{
		a = a->next;
		i++;
	}
	return (i);
}

static void	rotate1(int a_index, int b_index, t_data *data)
{
	if (b_index > data->len_b - b_index)
	{
		while ((a_index < data->len_a) && (b_index < data->len_b))
		{
			rev_rotate_r(data->a, data->b);
			a_index++;
			b_index++;
		}
		while (a_index++ < data->len_a)
			rev_rotate_a(data->a);
		while (b_index++ < data->len_b)
			rev_rotate_b(data->b);
	}
	else
	{
		while (a_index++ < data->len_a)
			rev_rotate_a(data->a);
		while (b_index--)
			rotate_b(data->b);
	}
}

static void	rotate2(int a_index, int b_index, t_data *data)
{
	if (b_index > data->len_b - b_index)
	{
		while (a_index--)
			rotate_a(data->a);
		while (b_index++ < data->len_b)
			rev_rotate_b(data->b);
	}
	else
	{
		while ((a_index > 0) && (b_index > 0))
		{
			rotate_r(data->a, data->b);
			a_index--;
			b_index--;
		}
		while (a_index-- > 0)
			rotate_a(data->a);
		while (b_index-- > 0)
			rotate_b(data->b);
	}
}

void	pick_and_push(t_list **a, t_list **b, t_data *data)
{
	int	a_index;
	int	b_index;
	int	pick_content;

	b_index = get_b_index(*b, data->len_b);
	pick_content = *lst_get_content(*b, b_index);
	a_index = get_a_index(*a, pick_content);
	if (a_index > data->len_a - a_index)
		rotate1(a_index, b_index, data);
	else
		rotate2(a_index, b_index, data);
	push_a(a, b, &data->len_a, &data->len_b);
}
