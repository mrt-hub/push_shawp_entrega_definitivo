# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtorrado <mtorrado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/01 17:43:39 by mtorrado          #+#    #+#              #
#    Updated: 2022/04/20 19:27:33 by mtorrado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBFT_PATH =libft/

LIBFT_LIB = $(LIBFT_PATH)libft.a

SRCS = push_swap.c\
		ft_int_atoi.c \
		check.c\
		utils.c\
		rotate.c\
		push.c  \
		swap.c 	\
		list.c  \
		list_utils.c \
		list_utils2.c \
		small.c \
		quick_sort.c \
		quick_sort_2.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(SRCS)
		make -C $(LIBFT_PATH) all
		$(CC) $(CFLAGS) $(SRCS) $(LIBFT_LIB) -o $(NAME)

clean:
	make -C $(LIBFT_PATH) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all
