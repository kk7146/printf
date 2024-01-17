# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eun <eun@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/06 09:51:37 by ajordan-          #+#    #+#              #
#    Updated: 2024/01/17 12:55:24 by eun              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#file name
NAME			=	libftprintf.a

#command
CC				=	gcc -Wall -Wextra -Werror
AR				=	ar
ARFLAGS 		=	rcs
RM				=	rm -rf

#directory
SRC_DIR			=	srcs/
INC_DIR			=	./includes/
LIB_DIR			=	./Libft
LIB_NAME		=	libft.a
LIBFT			=	$(addprefix $(LIB_DIR)/, $(LIB_NAME))

#srcs
SRCS			=	srcs/ft_printf.c srcs/ft_printf_print.c srcs/ft_printf_utils.c
OBJS			=	$(SRCS:.c=.o)

all:				$(NAME)

.c.o:
	$(CC) -c $< -o $(<:.c=.o) -I ../includes

$(NAME):			$(LIBFT) $(OBJS)
					cp $(LIBFT) $(NAME)
					$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(LIBFT):
					make -C $(LIB_DIR) all

clean:
					rm -f $(OBJS) ./srcs/$(NAME)
					make -C $(LIB_DIR) clean

fclean:				clean
					make -C $(LIB_DIR) fclean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re libft