/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libia.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 01:25:40 by albaud            #+#    #+#             */
/*   Updated: 2023/10/25 12:02:18 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBIA_H
# define LIBIA_H

# define NSIZE 6
# define MNEURON 50

# include <stdarg.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>
# include <math.h>
# include <pthread.h>
# include <stdio.h>
// # include "p/p.h"
// # include "mlib/mlib.h"
// # include "koflibc/sources.h"
# include "../libalbaud.h"
# include "libia_struct.h"
# include "ArtifialNeuronalNetwork/ann.h"
# include "Function/function.h"
// # include "cfiles/cfiles.h"
# define MINMAXRAND 0.5

t_data	read_csv_file(char *path, int inp_size, int out_size, int start, int length);

#endif