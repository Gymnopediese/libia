/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cfiles.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 00:41:29 by albaud            #+#    #+#             */
/*   Updated: 2023/02/14 20:13:01 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CFILES_H
# define CFILES_H

# include "../koflibc/sources.h"

int		f_file_size(char *file_name);
char	*f_read(char *file_name);
char	**f_readlines(char *file_name);
void	ft_atoia_fast(char *str, char split, double *buffer, int div);

#endif