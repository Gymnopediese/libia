/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:11:48 by albaud            #+#    #+#             */
/*   Updated: 2023/10/18 09:07:06 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libia.h"

#include <string.h>
#include <sys/errno.h>

void	ia_load(t_net *net, char *name)
{
	t_arr	temp;
	size_t	i;
	int	k;
	int	x;

	temp = readlines(name);
	i = -1;
	k = -1;
	while (++k < net->info.hiden_layers + 1)
	{
		x = -1;
		while (++i < temp.size && temp.arrays[i].chars[0] != '$')
			ft_atoia_fast(temp.arrays[i].chars, ',',
				net->weights[k].arr[++x].arr, 1);
	}
	k = -1;
	while (++i < temp.size && temp.arrays[i].chars[0] != '$')
		ft_atoia_fast(temp.arrays[i].chars, ',', net->bias[++k].arr, 1);
}

void	_save_bias(const t_net *net, int fd)
{
	int		i;
	int		x;

	i = -1;
	while (++i < net->info.hiden_layers + 1)
	{
		x = -1;
		while (++x < net->bias[i].size)
		{
			p(fd DD net->bias[i].arr[x] SS "," END);
		}
		p(fd NL END);
	}
}

void	_save_synaps(const t_net *net, int fd)
{
	int		i;
	int		x;
	int		y;

	i = -1;
	while (++i < net->info.hiden_layers + 1)
	{
		x = -1;
		while (++x < net->weights[i].size)
		{
			y = -1;
			while (++y < net->weights[i].arr->size)
				p(fd DD net->weights[i].arr[x].arr[y] SS "," END);
			p(fd NL END);
		}
		p(fd SS "$" NL END);
	}
}

void	ia_save(const t_net *net, ...)
{
	int		fd;
	char	b[1000];
	int		mode;
	t_str	bu;
	va_list	l;

	va_start(l, net);
	mode = va_arg(l, int);
	if (mode == SAVE_INT)
		bu = itoa(va_arg(l, int));
	strcpy(b, net->info.name);
	strcat(b, "/");
	strcat(b, bu.chars);
	strcat(b, ".snp");
	errno = 0;
	remove(b);
	fd = open(b, O_RDWR | O_CREAT, 0666);
	if (fd == -1 && p(1 SS strerror(errno) END))
		exit(1);
	_save_synaps(net, fd);
	_save_bias(net, fd);
	close(fd);
}
