#include "so_long.h"

void ft_up(t_solong *solong)
{
	int i;
	int j;

	i = solong->param->pos_x - 1;
	j = solong->param->pos_y;
	if (solong->param->map[i][j] == '1')
		return ;
	solong->param->count++;
	printf("%d\n", solong->param->count);
	if (solong->param->map[i][j] == 'C')
	{
		solong->param->map[i][j] = '0';
		solong->param->c--;
	}
	else if (solong->param->map[i][j] == 'E' && solong->param->c == 0)
	{
		printf ("You did it! GG!");
		solong->param->win = 1;
		//ft_win(solong);
	}
	solong->param->pos_x = i;
	solong->param->pos_y = j;
}

void	ft_down(t_solong *solong)
{
	int i;
	int j;

	i = solong->param->pos_x + 1;
	j = solong->param->pos_y;
	if (solong->param->map[i][j] == '1')
		return ;
	solong->param->count++;
	printf("%d\n", solong->param->count);
	if (solong->param->map[i][j] == 'C')
	{
		solong->param->map[i][j] = '0';
		solong->param->c--;
	}
	else if (solong->param->map[i][j] == 'E' && solong->param->c == 0)
	{
		printf ("You did it! GG!");
		solong->param->win = 1;
		//ft_win(solong);
	}
	solong->param->pos_x = i;
	solong->param->pos_y = j;
}

void	ft_right(t_solong *solong)
{
	int i;
	int j;

	i = solong->param->pos_x;
	j = solong->param->pos_y + 1;
	if (solong->param->map[i][j] == '1')
		return ;
	solong->param->count++;
	printf("%d\n", solong->param->count);
	if (solong->param->map[i][j] == 'C')
	{
		solong->param->map[i][j] = '0';
		solong->param->c--;
	}
	else if (solong->param->map[i][j] == 'E' && solong->param->c == 0)
	{
		printf ("You did it! GG!");
		solong->param->win = 1;
		//ft_win(solong);
	}
	solong->param->pos_x = i;
	solong->param->pos_y = j;
}

void	ft_left(t_solong *solong)
{
	int i;
	int j;

	i = solong->param->pos_x;
	j = solong->param->pos_y - 1;
	if (solong->param->map[i][j] == '1')
		return ;
	solong->param->count++;
	printf("%d\n", solong->param->count);
	if (solong->param->map[i][j] == 'C')
	{
		solong->param->map[i][j] = '0';
		solong->param->c--;
	}
	else if (solong->param->map[i][j] == 'E' && solong->param->c == 0)
	{
		printf ("You did it! GG!\n");
		solong->param->win = 1;
		//ft_win(solong);
	}
	solong->param->pos_x = i;
	solong->param->pos_y = j;
}

