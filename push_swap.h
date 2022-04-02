/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperegri <cperegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 01:30:41 by cperegri          #+#    #+#             */
/*   Updated: 2022/03/19 16:21:05 by cperegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				content;
	int				move_amount;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_data
{
	int				max;
	int				min;
	int				len_a;
	int				len_b;
	struct s_list	**a;
	struct s_list	**b;
}	t_data;

void		init_list(t_list **a, int argc, char **argv, int *len);

void		sort_six(t_list **a, t_list **b, t_data *data);
void		sort_big(t_list **a, t_list **b, t_data *data);
void		get_min_and_max(t_list *a, t_data *data);
void		pick_and_push(t_list **a, t_list **b, t_data *data);
void		final_rotate(t_list **a, t_data data);

int			str_is_numeric(char *str);
int			is_space(const char *c);
long int	atoi_(const char *str);

t_list		*lstnew(int content);
void		lstadd_front(t_list **lst, t_list *new, int *len);
void		lstclear(t_list *lst, int len);
int			*lst_get_content(t_list *lst, int index);
int			is_sort(t_list *lst, int len);

void		swap_a(t_list *a);
void		swap_b(t_list *b);
void		swap_ss(t_list *a, t_list *b);

void		push_a(t_list **a, t_list **b, int	*a_len, int *b_len);
void		push_b(t_list **a, t_list **b, int	*a_len, int *b_len);

void		rotate_a(t_list **a);
void		rotate_b(t_list **b);
void		rotate_r(t_list **a, t_list **b);

void		rev_rotate_a(t_list **a);
void		rev_rotate_b(t_list **b);
void		rev_rotate_r(t_list **a, t_list **b);
#endif
