#include "../includes/so_long.h"

int ft_start_game(t_param *param)
{
    void    *mlx;
    void    *mlx_window;
    t_img    img;
    (void)param;
    
    //printf("r1 = %d\nr2 = %d\n", param->x, param->y);
    mlx = mlx_init();
    mlx_window = mlx_new_window(mlx, 1920, 1080, "My so_long game");
    img.img = mlx_new_image(mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_pp, &img.line_length, &img.endian);
    my_mlx_pixel_put(&img, 50, 50, 0x00FF0000); // chger couleur + 5 et 5 (x et y) correspondent la position du pixel
    mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0); // a quoi correspondent les deux 0?
    mlx_loop(mlx);
    return (1);
}

void    my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
    char *dst;

    dst = img->addr + (y * img->line_length + x * (img->bits_pp / 8));
    *(unsigned int*)dst = color;
}
