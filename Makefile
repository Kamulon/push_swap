# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cperegri <cperegri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/30 06:32:36 by cperegri          #+#    #+#              #
#    Updated: 2022/03/23 15:05:17 by cperegri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
HEADER	=	push_swap.h
FLAGS	=	-Wall -Wextra -Werror
SRCS	=	main.c						\
			lst.c						\
			init.c						\
			sort_six.c					\
			sort_big.c					\
			pick_and_push.c				\
			final_rotate.c				\
			utils.c						\
			push.c						\
			swap.c						\
			rotate.c					\
			rev_rotate.c				\

OBJS	=	$(SRCS:.c=.o)
CC		=	gcc

all		:	
			@make $(NAME)
			
$(NAME)	:	$(OBJS) $(HEADER)
			$(CC) $(FLAGS) $(OBJS) -I $(HEADER) -o $(NAME) 
 
%.o		: 	%.c $(HEADER)
			$(CC) $(FLAGS) -c $< -o $@

ac		:
			@make all
			@make clean

clean	:
			/bin/rm -f $(OBJS) $(OBJSBS)

fclean	:	clean
			/bin/rm -f $(NAME)

re		:	fclean all

.PHONY	: 	all clean fclean re