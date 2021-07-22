/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti@student.42.fr <asgaulti>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 14:59:03 by asgaulti@st       #+#    #+#             */
/*   Updated: 2021/07/05 12:22:45 by asgaulti@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_start_game(t_solong *solong)
{
    t_img   img;
    t_square square;
    int x;
    int y;
    
    x = 42 * solong->param->size_y;
    y = 42 * solong->param->size_x;
    //ft_get_texture(solong);
    img.mlx = mlx_init();
    img.win = mlx_new_window(img.mlx, x, y, "Pingu's game");
    img.img = mlx_new_image(img.mlx, x, y);
    img.addr = mlx_get_data_addr(img.img, &img.bits_pp, &img.line_length, &img.endian);
    solong->img = &img;
    solong->square = &square;
    mlx_hook(img.win, 2, 1L<<0, ft_keypress, solong);
    mlx_hook(img.win, 17, 1L<<17, ft_close, solong);
    mlx_loop_hook(img.mlx, ft_minimap, solong);
    mlx_loop(img.mlx);
    return (1);
}

/*
apres avoir mis les textures et tout j'appellerai dans la fct finale le put_image_to_window
> lance une fct 
*/

int ft_minimap(t_solong *solong)
{
    int         i;
    int         j;
    char *count;

    i = 0;
    j = 0;
    ft_init_size_square(solong->square, i, j);
//  if (solong->param->win == 1)
//      ft_win(solong);
//  else
    {
        while (solong->param->map[i])
        {
            j = 0;
            while (solong->param->map[i][j])
            {
                ft_init_size_square(solong->square, i, j);
                if (solong->param->map[i][j] == '1')
                {    ft_draw_wall(solong->square, solong);
    //puts("che");
                }
                else if (solong->param->pos_x == i && solong->param->pos_y == j)
                    ft_draw_player(solong->square, solong);
                else if (solong->param->map[i][j] == 'C')
                    ft_draw_coll(solong->square, solong);
                else if (solong->param->map[i][j] == 'E')
                    ft_draw_exit(solong->square, solong);
                else
                    ft_draw_floor(solong->square, solong);
                j++;
            }
            i++;
        }
    }
    mlx_put_image_to_window(solong->img->mlx, solong->img->win, solong->img->img, 0, 0);
    count = ft_itoa(solong->param->count);
    mlx_string_put(solong->img->mlx, solong->img->win, SIZE / 2, SIZE / 2, BLACK, count);
    free(count);
    return (0);
}

void    ft_init_size_square(t_square *square, int i, int j)
{
    *square = (t_square){j * SIZE , i * SIZE , SIZE};
}

t_text	*ft_init_text(t_solong *solong)
{
    t_text  *text;

    text = malloc(sizeof(t_text));
    if (text == NULL)
        return (NULL);
	*text = (t_text){0, 0, 0, solong->param->size_x, 0, SIZE, SIZE};
    return (text);
}

void    ft_get_texture(t_solong *solong, int color, char *texture)
{
//    t_text text;

    // checker le .xpm > valide ou non (si non : exit)
    //if 
    
//	ft_init_text(&text);
//	solong->param->player = &text;
    if (color == 1)
	{
        solong->param->wall = ft_init_text(solong);
    //printf("a = %s w= %d h = %d\n", solong->param->floor->addr, solong->param->floor->width, solong->param->floor->height);
        if (solong->param->wall == NULL)
        {
            // msg erreur
            //puts("che");
            ft_close(solong);
        }
		if (ft_strncmp(texture, "wall.xpm", 8) == 0)
		{
			solong->param->wall->img = mlx_xpm_file_to_image(solong->img->mlx, "textures/wall.xpm", &solong->param->wall->width, &solong->param->wall->height);			
            if (solong->param->wall->img == NULL)
				ft_close(solong);
			solong->param->wall->addr = mlx_get_data_addr(solong->param->wall->img, &solong->param->wall->bpp, &solong->param->wall->line_length, &solong->param->wall->endian);
    	}
		else
		{
			ft_error_mlx(1);
			ft_close(solong);
		}
	}
    if (color == 2)
	{
        solong->param->floor = ft_init_text(solong);
    //printf("a = %s w= %d h = %d\n", solong->param->floor->addr, solong->param->floor->width, solong->param->floor->height);
        if (solong->param->floor == NULL)
        {
            // msg erreur
            //puts("che");
            ft_close(solong);
        }
		if (ft_strncmp(texture, "floor.xpm", 9) == 0)
		{
			solong->param->floor->img = mlx_xpm_file_to_image(solong->img->mlx, "textures/floor.xpm", &solong->param->floor->width, &solong->param->floor->height);			
            if (solong->param->floor->img == NULL)
				ft_close(solong);
			solong->param->floor->addr = mlx_get_data_addr(solong->param->floor->img, &solong->param->floor->bpp, &solong->param->floor->line_length, &solong->param->floor->endian);
    	}
		else
		{
			ft_error_mlx(1);
			ft_close(solong);
		}
	}
	if (color == 3)
	{
    solong->param->player = ft_init_text(solong);
    if (solong->param->player == NULL)
    {
        // msg erreur
        ft_close(solong);
    }
		if (ft_strncmp(texture, "pingu1.xpm", 10) == 0)
		{
			solong->param->player->img = mlx_xpm_file_to_image(solong->img->mlx, "textures/pingu1.xpm", &solong->param->player->width, &solong->param->player->height);			
            if (solong->param->player->img == NULL)
				ft_close(solong);
			solong->param->player->addr = mlx_get_data_addr(solong->param->player->img, &solong->param->player->bpp, &solong->param->player->line_length, &solong->param->player->endian);
    	}
		else
		{
			ft_error_mlx(1);
			ft_close(solong);
		}
	}
    if (color == 4)
	{
        solong->param->exit = ft_init_text(solong);
    //printf("a = %s w= %d h = %d\n", solong->param->floor->addr, solong->param->floor->width, solong->param->floor->height);
        if (solong->param->exit == NULL)
        {
            // msg erreur
            //puts("che");
            ft_close(solong);
        }
		if (ft_strncmp(texture, "exit.xpm", 8) == 0)
		{
			solong->param->exit->img = mlx_xpm_file_to_image(solong->img->mlx, "textures/exit.xpm", &solong->param->exit->width, &solong->param->exit->height);			
            if (solong->param->exit->img == NULL)
				ft_close(solong);
			solong->param->exit->addr = mlx_get_data_addr(solong->param->exit->img, &solong->param->exit->bpp, &solong->param->exit->line_length, &solong->param->exit->endian);
    	}
		else
		{
			ft_error_mlx(1);
			ft_close(solong);
		}
	}
    if (color == 5)
	{
        solong->param->collectible = ft_init_text(solong);
    //printf("a = %s w= %d h = %d\n", solong->param->floor->addr, solong->param->floor->width, solong->param->floor->height);
        if (solong->param->collectible == NULL)
        {
            // msg erreur
            //puts("che");
            ft_close(solong);
        }
		if (ft_strncmp(texture, "fish.xpm", 8) == 0)
		{
			solong->param->collectible->img = mlx_xpm_file_to_image(solong->img->mlx, "textures/fish.xpm", &solong->param->collectible->width, &solong->param->collectible->height);			
            if (solong->param->collectible->img == NULL)
				ft_close(solong);
			solong->param->collectible->addr = mlx_get_data_addr(solong->param->collectible->img, &solong->param->collectible->bpp, &solong->param->collectible->line_length, &solong->param->collectible->endian);
    printf("w = %d \n", solong->param->collectible->width);
    	}
		else
		{
			ft_error_mlx(1);
			ft_close(solong);
		}
	}
	// associer chaque texture a son char * dans la struct
    //solong->text = &text;
    // fct verif struct : si l'un des elements de la struct est nul : erreur
}

//void ft_verif_text()
