/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astridgaultier <astridgaultier@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 19:55:22 by astridgault       #+#    #+#             */
/*   Updated: 2021/06/08 22:31:40 by astridgault      ###   ########.fr       */
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
	//char	*line;
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
	//printf("map = %s\n", param->map[i]);
/*	while (data[i])
	{
		printf("%d - %s\n", i, data[i]);
		i++;
	}
*/	ft_stock_data(data, param);
	while (data[i])
		i++;
	if (ft_check_data(data, i, param) == 1)
	{
		//ft_free(data);
		return (0);
	}
	//printf("count = %d\n", count);
	//free(line);
	close (fd);
	//if (ft_check_data(param) == 0)
	//	return (1);
	return (0);
}


//stocker chaque ligne au fur et à mesure 
//+ stocker dans size_x la taille de la première ligne (i)
//+ stocker dans size_y le nombre de colonnes (j) [inutile? juste vérifier qu il n y a pas d espaces dans la map?]

//verifier que la taille de chaque ligne est égale à size_x

int		ft_stock_data(char	**data, t_param *param)
{
	int i;
	int j;

	i = 0;
	// manque le malloc pour map?
	while (data[i])
	{
		j = 0;
		while (data[i][j])
		{
			param->map[i][j] = data[i][j];
			j++;
		}
		i++;
	printf("data = %s\n", data[i]);
	}
	i = 0;
	while (param)
	{
		printf("%d - %s\n", i, param->map[i]);
		i++;
	}
	printf("%d - %s\n", i, data[i]);
	return (1);
}


int	ft_check_data(char **data, int count, t_param *param)
{
	int i;
	int j;

	i = 0;
	// check 1ere et derniere ligne:
	while (i < count)
	{
		j = 0;
		if (i == 0 || i == count - 1)
		{
			while (data[i][j])
			{
				if (data[i][j] != '1')
				{
					ft_error_map(1);
					return (1);
				}
				j++;
			}
		}
		i++;
	}
	// check char à faire avant rectangle (pour verifier qu'il n'y a pas d'espace):
	
	// check rectangle :
	while (data[0][j])
		j++;
	param->size = j;
	i = 1;
	while (i < count)
	{
			printf("data[%i] = %s\n", i, data[i]);
		j = 0;
		while (data[i][j])
			j++;
		printf("j = %d  size = %d\n", j, param->size);
		if (j != param->size)
		{
			ft_error_map(1);
			return (1);
		}
		i++;
	}
	return (0);
}