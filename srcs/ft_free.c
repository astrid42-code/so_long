/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astridgaultier <astridgaultier@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 19:59:09 by astridgault       #+#    #+#             */
/*   Updated: 2021/06/06 20:03:53 by astridgault      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free_map(t_param *param)
{
	int i;

	i = 0;
	//printf("par-i = %d\n", param->i);
	while (i <= param->i)
	{
		//printf("data[%d]-> %s->%p\n", i, param->map[i], param->map[i]);
		free(param->map[i]);
		param->map[i] = NULL;
		i++;
		//printf("i = %d\n", i);
	}
	//printf("i = %d\n", i);
	free(param->map);
}
