/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperegri <cperegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 01:29:57 by cperegri          #+#    #+#             */
/*   Updated: 2022/03/23 13:47:35 by cperegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_data(t_list **a, t_list **b, t_data *data)
{
	*a = 0;
	*b = 0;
	data->a = a;
	data->b = b;
	data->len_a = 0;
	data->len_b = 0;
	data->max = 0;
	data->min = 0;
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	t_data	data;

	init_data(&a, &b, &data);
	init_list(&a, argc, argv, &data.len_a);
	if (is_sort(a, data.len_a))
		exit (0);
	else if (data.len_a < 7)
		sort_six(&a, &b, &data);
	else
		sort_big(&a, &b, &data);
	lstclear(a, data.len_a);
	return (0);
}
