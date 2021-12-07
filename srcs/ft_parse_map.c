/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti@student.42.fr <asgaulti>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 19:55:22 by astridgault       #+#    #+#             */
/*   Updated: 2021/07/30 14:47:34 by asgaulti@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_read_data(int fd, t_param *param)
{
	char	**data;
	int		i;

	fd = open(param->file, O_RDONLY);
	if (read(fd, 0, 0) == -1)
		ft_error_dir(param);
	if (fd < 0)
		return (write(1, "Error\nNo file\n", 14) && 1);
	i = 0;
	data = ft_get_file(fd, 0);
	while (data[i])
		i++;
	if (ft_stock_data(data, param, i) == 1)
	{
		free(data);
		return (1);
	}
	if (ft_check_data(i, param) == 1)
	{
		free(data);
		return (1);
	}
	close (fd);
	free(data);
	return (0);
}

int	ft_stock_data(char	**data, t_param *param, int count)
{
	int	i;

	i = 0;
	param->map = malloc (sizeof(char *) * (count + 1));
	if (!param->map)
		return (1);
	while (data[i])
	{
		param->map[i] = data[i];
		i++;
	}
	param->size_x = i;
	param->map[i] = NULL;
	return (0);
}

int	ft_check_data(int count, t_param *param)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (param->map[0][j])
		j++;
	param->size = j;
	param->size_y = j;
	j = 0;
	if (ft_check_charmap(i, j, param, count) == 1)
		return (1);
	i = 0;
	if (ft_check_one(i, count, param) == 1)
		return (1);
	if (ft_check_rectangle(count, param) == 1)
		return (1);
	return (0);
}

int	ft_check_charmap(int i, int j, t_param *param, int count)
{
	while (++i < count)
	{
		j = -1;
		while (++j < param->size)
		{
			if (param->map[i][j] != '0' && param->map[i][j] != '1' &&
			param->map[i][j] != 'C' && param->map[i][j] != 'E' &&
			param->map[i][j] != 'P')
			{
				ft_error_map(1);
				return (1);
			}
			if (param->map[i][j] == 'C' || param->map[i][j] == 'E' ||
					param->map[i][j] == 'P')
				ft_count_c_e(i, j, param);
			if (param->p > 1)
			{
				ft_error_map(2);
				return (1);
			}
		}
	}
	if (ft_check_letters(param) == 1)
		return (1);
	return (0);
}
