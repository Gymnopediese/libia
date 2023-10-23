/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:46:21 by albaud            #+#    #+#             */
/*   Updated: 2023/10/23 18:05:06 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libia.h"
#include <stdlib.h>

int	_load_infos(t_net *net, t_arr *lines)
{
	int	i;
	int	k;

	i = 0;
	net->info.name = copy(&lines->arrays[i++]).chars;
	net->info.inputs = atoi(lines->arrays[i++].chars);
	net->info.outputs = atoi(lines->arrays[i++].chars);
	net->info.learning = atof(lines->arrays[i++].chars);
	net->info.function = atoi(lines->arrays[i++].chars);
	net->info.hiden_layers = atoi(lines->arrays[i++].chars);
	net->info.hiden_layers_size = new(net->info.hiden_layers, 4);
	k = -1;
	while (++k < net->info.hiden_layers)
		net->info.hiden_layers_size[k] = atoi(lines->arrays[i++].chars);
	return (i);

}

t_net	ia_load(char *filename)
{
	t_net	res;
	t_arr	lines;
	size_t	line;
	int		k;
	int		x;

	lines = readlines(filename);
	line = _load_infos(&res, &lines) - 1;
	init_neuronal_network(&res, res.info);
	print_net(&res);
	k = -1;
	while (++k < res.info.hiden_layers + 1)
	{
		x = -1;
		while (++line < lines.size && lines.arrays[line].chars[0] != '$')
			atoia(res.weights[k].arr[++x].arr, lines.arrays[line].chars, ",");
	}
	printf("line: %zu\n", line);
	k = -1;
	while (++line < lines.size && lines.arrays[line].chars[0] != '$')
		atoia(res.bias[++k].arr, lines.arrays[line].chars, ",");
	printf("line: %zu\n", line);
	return (res);
}
