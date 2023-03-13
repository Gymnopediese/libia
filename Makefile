# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albaud <albaud@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/18 13:07:44 by albaud            #+#    #+#              #
#    Updated: 2023/03/13 13:30:21 by albaud           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS 	= init_env.c move.c GA/genetique.c GAN/gan.c NeuronalNetwork/forward.c NeuronalNetwork/init_net.c NeuronalNetwork/save.c NeuronalNetwork/train.c cfiles/atoia.c cfiles/f_file_size.c cfiles/f_read.c cfiles/f_readlines.c function/ia_relu.c function/ia_sigmoid.c k_voisins/k_voisin.c mlx_drawing/hooks.c mlx_drawing/hooks2.c p/main.c p/p.c p/progressbar.c qlearning_network/q_learning.c visualizer/positions.c visualizer/vis_neurones.c visualizer/vis_synaps.c visualizer/visualizer.c
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
		ar rcs ${NAME} ${OBJS} ${LIBS}

c 		:
		find *.c */*.c | grep -v m_ | grep -v mini | tr '\n' ' '
		
clean	:
		rm -f ${OBJS}

fclean	:	clean
		make fclean -C mlib
		make fclean -C mlib/vlib
		rm -f ${NAME}

re		: fclean all

