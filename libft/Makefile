# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtorrado <mtorrado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/27 17:52:27 by mtorrado          #+#    #+#              #
#    Updated: 2021/11/25 17:39:35 by mtorrado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_memset.c			\
			ft_bzero.c		\
			ft_memcpy.c		\
			ft_memccpy.c	\
			ft_memmove.c	\
			ft_memchr.c		\
			ft_memcmp.c		\
			ft_strlen.c		\
			ft_strlcpy.c	\
			ft_strlcat.c	\
			ft_strchr.c		\
			ft_strrchr.c	\
			ft_strnstr.c	\
			ft_strncmp.c	\
			ft_atoi.c		\
			ft_isalpha.c	\
			ft_idigit.c		\
			ft_isalnum.c	\
			ft_isascii.c	\
			ft_isprint.c	\
			ft_toupper.c	\
			ft_tolower.c	\
			ft_calloc.c		\
			ft_calloc2.c 	\
			ft_strdup.c		\
			ft_substr.c		\
			ft_strjoin.c	\
			ft_strjoin2.c 	\
			ft_strtrim.c	\
			ft_split.c		\
			ft_itoa.c		\
			ft_strmapi.c	\
			ft_putchar_fd.c	\
			ft_putstr_fd.c	\
			ft_putendl_fd.c	\
			ft_putnbr_fd.c	\
			get_line_lengt.c \

SRCSB = ft_lstnew.c				\
			ft_lstadd_front.c	\
			ft_lstsize.c		\
			ft_lstlast.c		\
			ft_lstadd_back.c	\
			ft_lstdelone.c		\
			ft_lstclear.c		\
			ft_lstiter.c		\
			ft_lstmap.c

NAME = libft.a


OBJS = $(SRCS:.c=.o)


OBJSB = $(OBJS) $(SRCSB:.c=.o)


CC = gcc


CC_FLAGS = -c -Wall -Wextra -Werror


$(NAME): $(OBJS)
		$(CC) $(SRCS) libft.h $(CC_FLAGS)
		ar r $(NAME) $(OBJS)
		@echo "[INFO] libray created"

all: $(NAME)

clean: 
	rm -f $(OBJSB)
	@echo "[INFO] object removed"

fclean:	clean
	rm -f $(NAME)
	echo "[INFO] library [$(NAME)] removed"

re:	fclean all

bonus:	$(OBJSB)
	$(CC) $(SRCS) $(SRCSB) $(CC_FLAGS)
	ar r $(NAME) $(OBJSB)
	@echo "[INFO] Bonus funtions added to libft.a"


