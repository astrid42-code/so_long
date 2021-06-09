/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti@student.42.fr <asgaulti>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 19:59:09 by astridgault       #+#    #+#             */
/*   Updated: 2021/06/09 16:05:54 by asgaulti@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

void	ft_free(char **data)
{
	int i;

	i = 0;
	//printf("par-i = %d\n", param->i);
	while (data[i])
	{
		//printf("data[%d]-> %s->%p\n", i, param->map[i], param->map[i]);
		free(data[i]);
		data[i] = NULL;
		i++;
		//printf("i = %d\n", i);
	}
	//printf("i = %d\n", i);
	free(data);
}
