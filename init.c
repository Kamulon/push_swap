/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperegri <cperegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 23:48:17 by cperegri          #+#    #+#             */
/*   Updated: 2022/03/23 13:51:44 by cperegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	error(t_list *lst, int len)
{
	write(1, "Error\n", 6);
	if (lst && len)
		lstclear(lst, len);
	exit(0);
}

static int	check_duplicate(int num, t_list *lst, int len)
{
	while (len--)
	{
		if (lst->content == num)
			return (0);
		lst = lst->next;
	}
	return (1);
}

static void	check_args(int argc, char **argv)
{
	if (argc == 1)
		exit(0);
	while (argc - 1)
	{
		if (str_is_numeric(argv[argc - 1]) && *argv[argc - 1])
			argc--;
		else
			error(0, 0);
	}
	return ;
}

void	init_list(t_list **a, int argc, char **argv, int *len)
{
	long int	num;

	check_args(argc, argv);
	while (argc-- > 1)
	{
		num = atoi_(argv[argc]);
		if (num > 2147483647)
			error(*a, *len);
		if (num < -2147483648)
			error(*a, *len);
		if (!check_duplicate(num, *a, *len))
			error(*a, *len);
		lstadd_front(a, lstnew(num), len);
	}
	return ;
}
