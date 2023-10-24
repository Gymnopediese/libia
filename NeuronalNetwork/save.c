/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:11:48 by albaud            #+#    #+#             */
/*   Updated: 2023/10/24 12:01:52 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libia.h"

#include <string.h>
#include <sys/errno.h>

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

void	_save_infos(const t_net *net, int fd)
{
	int	i;

	i = -1;
	p(fd SS net->info.name NL END);
	p(fd II net->info.inputs NL END);
	p(fd II net->info.outputs NL END);
	p(fd DD net->info.learning NL END);
	p(fd II net->info.function NL END);
	p(fd II net->info.hiden_layers NL END);
	while (++i < net->info.hiden_layers)
		p(fd II net->info.hiden_layers_size[i] NL END);
}

void	ia_save(const t_net *net, ...)
{
	int		fd;
	t_str	name;
	char	*str;
	va_list	l;

	va_start(l, net);
	str = va_arg(l, char *);
	name = va_format(str, &l);
	prepend(&name, s("save/"));
	remove(name.chars);
	fd = open(name.chars, O_RDWR | O_CREAT, 0666);
	assert(fd == -1, "cannot save synaps");
	_save_infos(net, fd);
	_save_synaps(net, fd);
	_save_bias(net, fd);
	close(fd);
	printf("synapses saved in %s\n", name.chars);
}
