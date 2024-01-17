# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donson <donson@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/06 09:51:37 by ajordan-          #+#    #+#              #
#    Updated: 2024/01/15 19:02:36 by donson           ###   ########.fr        #
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
SRCS			=	srcs/ft_printf.c srcs/ft_printf_ptr.c srcs/ft_printf_num.c srcs/ft_printf_convert.c
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