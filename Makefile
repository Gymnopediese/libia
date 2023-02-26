# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albaud <albaud@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/18 13:07:44 by albaud            #+#    #+#              #
#    Updated: 2023/02/21 11:48:44 by albaud           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS 	= forward.c ia_relu.c ia_sigmoid.c init_net.c k_voisin.c save.c train.c
OBJS 	= ${SRCS:.c=.o}
NAME 	= libia.a
LIBS 	= mlib/mlib.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

.c.o 	:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
		
all 	: $(NAME)

$(NAME)	: ${OBJS}
		make -C mlib
		ar rcs ${NAME} ${OBJS} ${LIBS}

c 		:
		find *.c | tr '\n' ' '
		
clean	:
		rm -f ${OBJS}

fclean	:	clean
		rm -f ${NAME}

re		: fclean all

