# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: coder <coder@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/10 16:50:19 by leolipes          #+#    #+#              #
#    Updated: 2022/02/09 22:10:12 by coder            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCR	=	ft_printf.c \
			ft_printf_utils.c \
			ft_hexa_and_pointer.c

OBJS	= ${SRCR:.c=.o}

NAME	= libftprintf.a

CC		= gcc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
