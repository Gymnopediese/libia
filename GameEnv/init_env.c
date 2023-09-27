/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:55:40 by albaud            #+#    #+#             */
/*   Updated: 2023/09/27 09:37:20 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libia.h"

t_env	init_env(void *env, ...)
{
	t_env	res;
	va_list	list;

	va_start(list, env);
	res.env = env;
	res.step = va_arg(list, t_intf);
	res.reset = va_arg(list, t_voidf);
	res.draw = va_arg(list, t_voidf);
	res.state = va_arg(list, t_voidf);
	res.value = va_arg(list, t_doublef);
	return (res);
}
