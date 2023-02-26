# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albaud <albaud@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/18 13:07:44 by albaud            #+#    #+#              #
#    Updated: 2023/02/21 11:10:47 by albaud           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS 	= m_add.c m_apply.c m_clear.c m_dot.c m_mult.c m_new.c m_print.c m_rand.c m_subs.c m_vdot.c
OBJS 	= ${SRCS:.c=.o}
NAME 	= mlib.a
LIBS 	= vlib/vlib.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

.c.o 	:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
		
all 	: $(NAME)

$(NAME)	: ${OBJS}
		make -C vlib
		ar rcs ${NAME} ${OBJS} ${LIBS}

c 		:
		find *.c | tr '\n' ' '
		
clean	:
		rm -f ${OBJS}

fclean	:	clean
		rm -f ${NAME}

re		: fclean all

