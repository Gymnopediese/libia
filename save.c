/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:11:48 by albaud            #+#    #+#             */
/*   Updated: 2023/02/27 00:40:36 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libia.h"

#include <string.h>
#include <sys/errno.h>

void	ia_load(t_net *net, char *name)
{
	char	**temp;
	int		i;
	int		k;
	int		x;

	temp = f_readlines(name);
	i = -1;
	k = -1;
	while (++k < net->info.hiden_layers + 1)
	{
		x = -1;
		while (temp[++i] && temp[i][0] != '$')
			ft_atoia_fast(temp[i], ',', net->weights[k].arr[++x].arr, 1);
	}
	k = -1;
	while (temp[++i] && temp[i][0] != '$')
		ft_atoia_fast(temp[i], ',', net->bias[++k].arr, 1);
	ft_free_pp((void **)temp);
}

void	ia_save(const t_net *net, char *name)
{
	int		i;
	int		x;
	int		y;
	int		fd;
	char	b[1000];

	strcpy(b, net->name);
	ft_strcat(b, "/");
	strcat(b, name);
	ft_strcat(b, ".snp");
	errno = 0;
	remove(b);
	fd = open(b, O_RDWR | O_CREAT, 0666);
	if (fd == -1 && p(1 SS strerror(errno) END))
		exit(1);
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
	i = -1;
	while (++i < net->info.hiden_layers + 1)
	{
		x = -1;
		while (++x < net->bias[i].size)
		{
			y = -1;
			p(fd DD net->bias[i].arr[x] SS "," END);
		}
		p(fd NL END);
	}
	close(fd);
}
