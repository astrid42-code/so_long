/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti@student.42.fr <asgaulti>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 19:59:09 by astridgault       #+#    #+#             */
/*   Updated: 2021/06/24 11:32:37 by asgaulti@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(t_param *param)
{
	int i;

	i = 0;
	//printf("par-i = %d\n", param->i);
	while (param->map[i])
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

void	ft_free(t_param *param)
{
	if (param->map)
		ft_free_map(param);
	if (param->file)
		free(param->file);
}
