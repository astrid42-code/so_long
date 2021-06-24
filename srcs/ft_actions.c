#include "so_long.h"

void ft_up(t_solong *solong)
{
	int i;
	int j;

	i = solong->param->pos_x;
	j = solong->param->pos_y;
	if (solong->param->map[i - 1][j] == 'E')
		ft_close(solong);
	else if (solong->param->map[i - 1][j] == 'C'
		|| solong->param->map[i - 1][j] == '0')
	{
	puts("che");
		ft_draw_floor(solong->square, solong);
		i--;
		solong->param->pos_x = i;
		ft_draw_player(solong->square, solong);
		// + rajouter un compteur de collectible??
	}
    else if (solong->param->map[i - 1][j] != '1'
		&& solong->param->map[i - 1][j] != 'E'
		&& solong->param->map[i - 1][j] != 'C')
	{
		ft_draw_floor(solong->square, solong);
		i--;
		solong->param->pos_x = i;
		ft_draw_player(solong->square, solong);
	}
	else
		return ;	
}
