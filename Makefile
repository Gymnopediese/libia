# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albaud <albaud@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/18 13:07:44 by albaud            #+#    #+#              #
#    Updated: 2023/03/09 12:41:31 by albaud           ###   ########.fr        #
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
		make -C mlib/vlib
		make -C p
		make -C koflibc
		ar rcs ${NAME} ${OBJS} ${LIBS}

c 		:
		find *.c */*.c | grep -v m_ | tr '\n' ' '
		
clean	:
		make clean -C mlib
		make clean -C mlib/vlib
		make clean -C p
		make clean -C koflibc
		rm -f ${OBJS}

fclean	:	clean
		make fclean -C mlib
		make fclean -C mlib/vlib
		make fclean -C p
		make fclean -C koflibc
		rm -f ${NAME}

re		: fclean all

