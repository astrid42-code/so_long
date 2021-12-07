/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:54:39 by asgaulti@st       #+#    #+#             */
/*   Updated: 2021/07/26 12:19:55 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_one(int i, int count, t_param *param)
{
	int	j;

	while (i < count)
	{
		j = 0;
		if (i == 0 || i == count - 1)
		{
			while (param->map[i][j])
			{
				if (param->map[i][j] != '1')
				{
					ft_error_map(1);
					return (1);
				}
				j++;
			}
		}
		i++;
	}
	if (ft_check_one_borders(count, param) == 1)
		return (1);
	return (0);
}

int	ft_check_one_borders(int count, t_param *param)
{
	int	i;

	i = 1;
	while (i < count - 1)
	{
		if (param->map[i][0] != '1' || param->map[i][param->size - 1] != '1')
		{
			ft_error_map(1);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_check_rectangle(int count, t_param *param)
{
	int	i;
	int	j;

	i = 1;
	while (i < count)
	{
		j = 0;
		while (param->map[i][j])
			j++;
		if (j != param->size)
		{
			ft_error_map(1);
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_count_c_e(int i, int j, t_param *param)
{
	if (param->map[i][j] == 'C')
		param->c++;
	if (param->map[i][j] == 'E')
		param->e++;
	if (param->map[i][j] == 'P')
	{
		param->pos_x = i;
		param->pos_y = j;
		param->p++;
	}
}

int	ft_check_letters(t_param *param)
{
	if (param->p < 1)
	{
		ft_error_map(3);
		return (1);
	}
	if (param->c < 1)
	{
		ft_error_map(4);
		return (1);
	}
	if (param->e < 1)
	{
		ft_error_map(5);
		return (1);
	}
	return (0);
}
