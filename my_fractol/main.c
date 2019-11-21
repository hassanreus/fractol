# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>

typedef struct	s_fractol
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
    int         *data;
    int			size_line;
	int			bpp;
	int			endian;
	double		zoom;
	double		o_x;
	double		o_y;
    int			fract;
	int			color;
	int			it;
	int			it_max;
	double		c_rel;
	double		c_img;
	double		z_rel;
	double		z_img;
	double		preview;
}				t_fractol;

static	void	put_pixel(t_fractol *fractol, int x, int y, int color)
{
	if (x < 1000 && x >= 0 && y >= 0 && y < 1000)
		fractol->data[x + y * 1000] = color;
}


void	mandelbrot_calc(t_fractol *fractol,int i,int j)
{
	fractol->c_rel = i/ fractol->zoom + fractol->o_x;
	fractol->c_img = j / fractol->zoom + fractol->o_y;
	fractol->z_rel = 0;
	fractol->z_img = 0;
	fractol->it = 0;
	while (fractol->z_rel * fractol->z_rel + fractol->z_img *
			fractol->z_img < 4 && fractol->it < fractol->it_max)
	{
		fractol->preview = fractol->z_rel;
		fractol->z_rel = fractol->z_rel * fractol->z_rel -
			fractol->z_img * fractol->z_img + fractol->c_rel;
		fractol->z_img = 2 * fractol->z_img * fractol->preview + fractol->c_img;
		fractol->it++;
	}
	if (fractol->it == fractol->it_max)
		put_pixel(fractol, i, j, 0x000000);
	else
		put_pixel(fractol, i, j, (fractol->color * fractol->it));
}

void	mandelbrot(t_fractol *fractol)
{
	int i;
    int j;

    i = 0;
	while (i < 1000)
	{
		j = 0;
		while (j < 1000)
		{
			mandelbrot_calc(fractol,i,j);
			j++;
		}
		i++;
	}
}


void    initialize(t_fractol *fractol,char *argv)
{
	fractol->mlx_ptr = mlx_init();
	fractol->win_ptr = mlx_new_window(fractol->mlx_ptr, 1000, 1000, argv);
	fractol->img_ptr = mlx_new_image(fractol->mlx_ptr, 1000, 1000);
	fractol->data = (int *)mlx_get_data_addr(fractol->img_ptr, &(fractol->bpp),\
			&(fractol->size_line), &(fractol->endian));
    ////////mandelbrot//////////
    fractol->it_max = 50;
	fractol->zoom = 250;
	fractol->o_x = -2;
	fractol->o_y = -2;
	fractol->color = 0xffabe3;
	mandelbrot(fractol);
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr, fractol->img_ptr, 0, 0);
	

}
int		is_fractol(char *argv)
{
	if (ft_strcmp(argv, "mandelbrot") == 0)
		return (1);
	 if (ft_strcmp(argv, "julia") == 0)
		return (2);
	 if (ft_strcmp(argv, "burningship") == 0)
		return (3);
	return (0);
}

// int mouse_press(int button, int x, int y, t_fractol *fractol)
// {
// 	if(button == 4)
// 	{
// 		printf("(%d,%d)%d\n",x,y,fractol->bpp);
// 	}
// 	return (0);
// }

// void control(t_fractol *fractol)
// {
// 	 mlx_hook(fractol->win_ptr, 4, 0, mouse_press, fractol);
// }

int main(int argc,char **argv)
{
    t_fractol *fractol;
    if(argc == 2)
    {
        if (!(fractol = (t_fractol *)malloc(sizeof(t_fractol))))
			return (0);
        if((fractol->fract = is_fractol(argv[1])))
        {
			initialize(fractol,argv[1]);
			// control(fractol);
			mlx_loop(fractol->mlx_ptr);
			return (0);
        }
    }
     ft_putendl("Usage /fractol \"mandelbrot\", \"julia\", \"burningship\"");
    return (0);
}