/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti@student.42.fr <asgaulti>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 19:55:22 by astridgault       #+#    #+#             */
/*   Updated: 2021/06/15 17:19:36 by asgaulti@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"



/*
vérifier qu il y a bien des 1 tout autour de la map

vérifier qu il n y a pas : 
    d espaces dans la map (error 1)
    au moins un E (error 5)
    au moins un C (error 4)
    un joueur et un seul / le starting point (P) (error 3 et 2)
    et uniquement des 0 et des 1 (error 1)


free la map à la fin du main
*/

//ouvrir/lire le fichier (copié dans map.file) :
int		ft_read_data(int fd, t_param *param)
{
	char	**data;
    int     i;
	int		count;

	count = 0;
	printf("Opening map\n");
	fd = open(param->file, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\n");
		printf("No file\n");
		return (1);
	}
	printf("Reading map\n");
	i = 0;
	data = ft_get_file(fd, 0);
/*	//printf("map = %s\n", param->map[i]);
	while (data[i])
	{
		printf("%d - %s\n", i, data[i]);
		i++;
	}
*/	while (data[i])
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
	//printf("count = %d\n", count);
	//free(line);
	close (fd);
	//if (ft_check_data(param) == 0)
	//	return (1);
	//ft_free(data);
	free(data);
	return (0);
}



//stocker chaque ligne au fur et à mesure 
int		ft_stock_data(char	**data, t_param *param, int count)
{
	int i;

	i = 0;
	param->map = malloc (sizeof(char*) * (count + 1));
	if (!param->map)
		return (1);
	while (data[i]) // ou tq i < count?
	{
		param->map[i] = data[i];
		//printf("map[%d] = %s\n", i, param->map[i]);
		i++;
	}
	param->size_x = i;
	param->map[i] = NULL;
	//printf("map[%d] = %s\n", i, param->map[i]);
	return (0);
}

int	ft_check_data(int count, t_param *param)
{
	int i;
	int j;

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

int		ft_check_charmap(int i, int j,t_param *param, int count)
{
	while (++i < count)
	{
		j = -1;
		while (++j < param->size)
		{
			if (param->map[i][j] != '0' && param->map[i][j] != '1' &&
			param->map[i][j] != 'C' && param->map[i][j] != 'E' && param->map[i][j] != 'P')
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
