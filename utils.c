/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperegri <cperegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 00:02:37 by cperegri          #+#    #+#             */
/*   Updated: 2022/03/23 13:51:32 by cperegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_digit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	str_is_numeric(char *str)
{
	if (*str == '-')
		str++;
	while (*str)
	{
		if (is_digit(*str))
			str++;
		else
			return (0);
	}
	return (1);
}

long int	atoi_(const char *str)
{
	int			minus;
	long int	nb;

	minus = 1;
	nb = 0;
	if (*str == '-')
	{
		minus = -1;
		str++;
	}
	while (is_digit(*str))
		nb = (nb * 10) + *str++ - '0';
	return (nb * minus);
}
