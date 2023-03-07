# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albaud <albaud@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/18 13:07:44 by albaud            #+#    #+#              #
#    Updated: 2023/03/07 23:18:14 by albaud           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS 	= NeuronalNetwork/forward.c NeuronalNetwork/init_net.c NeuronalNetwork/save.c NeuronalNetwork/train.c function/ia_relu.c function/ia_sigmoid.c k_voisins/k_voisin.c visualizer/positions.c visualizer/vis_neurones.c visualizer/vis_synaps.c visualizer/visualizer.c
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
		find *.c */*.c | grep -v m_ | tr '\n' ' '
		
clean	:
		rm -f ${OBJS}

fclean	:	clean
		rm -f ${NAME}

re		: fclean all

