/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperegri <cperegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 23:45:07 by cperegri          #+#    #+#             */
/*   Updated: 2022/03/23 13:47:36 by cperegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lstnew(int content)
{
	t_list	*new_elem;

	new_elem = malloc(sizeof(t_list));
	if (new_elem)
	{
		new_elem->content = content;
		new_elem->next = new_elem;
		new_elem->prev = new_elem;
		new_elem->move_amount = 0;
	}
	return (new_elem);
}

void	lstadd_front(t_list **lst, t_list *new, int *len)
{
	if (!lst || !new)
		return ;
	if (*len == 0)
	{
		*lst = new;
		new->next = new;
		new->prev = new;
		(*len)++;
		return ;
	}
	new->next = *lst;
	new->prev = (*lst)->prev;
	(*lst)->prev->next = new;
	(*lst)->prev = new;
	*lst = new;
	(*len)++;
}

void	lstclear(t_list *lst, int len)
{
	t_list	*buf;

	if (!lst)
		return ;
	while (len--)
	{
		buf = lst;
		lst = lst->next;
		free(buf);
	}
	return ;
}

int	*lst_get_content(t_list *lst, int index)
{
	if (index)
		return (lst_get_content(lst->next, --index));
	else
		return (&lst->content);
}

int	is_sort(t_list *lst, int len)
{
	if (len == 1)
		return (1);
	else if (lst->content < lst->next->content)
		return (is_sort(lst->next, --len));
	return (0);
}
