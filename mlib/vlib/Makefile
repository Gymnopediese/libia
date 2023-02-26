# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albaud <albaud@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/18 13:07:44 by albaud            #+#    #+#              #
#    Updated: 2023/02/23 15:31:49 by albaud           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS 	= rand.c v_add.c alo.c v_range.c v_apply.c v_average.c v_clear.c v_dist.c v_dot.c v_error.c v_min.c v_mult.c v_new.c v_omax.c v_print.c v_rand.c v_subs.c v_sum.c v_tocol.c
OBJS 	= ${SRCS:.c=.o}
NAME 	= vlib.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

.c.o 	:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
		
all 	: $(NAME)

$(NAME)	: ${OBJS}
		ar rcs ${NAME} ${OBJS}

c 		:
		find *.c */*.c | grep -v p/ | grep -v bx | tr '\n' ' '
		
clean	:
		rm -f ${OBJS}

fclean	:	clean
		rm -f ${NAME}

re		: fclean all

