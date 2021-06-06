/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astridgaultier <astridgaultier@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 19:55:22 by astridgault       #+#    #+#             */
/*   Updated: 2021/06/06 20:32:34 by astridgault      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"




vérifier qu il y a bien des 1 tout autour de la map

vérifier qu il n y a pas : 
    d espaces dans la map (error 1)
    au moins un E (error 5)
    au moins un C (error 4)
    un joueur et un seul / le starting point (P) (error 3 et 2)
    et uniquement des 0 et des 1 (error 1)


free la map à la fin du main


//ouvrir/lire le fichier (copié dans map.file) :
int		ft_read_data(int fd, t_param *param)
{
	char	*line;
    int     x;

	printf("Opening map\n");
	fd = open(param->mapfile, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\n");
		printf("No file\n");
		return (1);
	}
	printf("Reading map\n");
	while (get_next_line(fd, &line) > 0)
	{
		ft_stock_data(line, param);
		free(line);
	}
	//ft_stock_data(line, param);
	free(line);
	close (fd);
	if (ft_check_data(param) == 0)
		return (1);
	return (0);
}


//stocker chaque ligne au fur et à mesure 
//+ stocker dans size_x la taille de la première ligne (i)
//+ stocker dans size_y le nombre de colonnes (j) [inutile? juste vérifier qu il n y a pas d espaces dans la map?]

verifier que la taille de chaque ligne est égale à size_x

int		ft_stock_data(char	*line, t_param *param)
{

	return (1);
}
