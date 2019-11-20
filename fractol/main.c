/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseffian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:00:49 by hseffian          #+#    #+#             */
/*   Updated: 2019/10/31 12:00:51 by hseffian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void        ft_usage(void)
{
    ft_putendl("usage : fractol [fractols]");
    ft_putendl(" fractals :");
    ft_putendl("---> Madelbrot");
    ft_putendl("---> Julia");
}


int     is_fract(char *av)
{
    if (ft_strcmp(av, "Mandelbrot") == 0)
        return (1);
    if (ft_strcmp(av, "Julia") == 0)
        return (2);
    return (0);
}

static	void	put_pixel(t_fractol *fractol, int x, int y, int color)
{
	if (x < 1000 && x >= 0 && y >= 0 && y < 1000)
		fractol->data[x + y * 1000] = color;
}

void put_pixel2(int x, int y)
{
    ft_putnbr(x);
    ft_putchar('\n');
    ft_putnbr(y);
}

void	madelbrot_cl(t_fractol *fractol, int i, int j)
{
	fractol->c_r = i/ fractol->zoom + fractol->x;
	fractol->c_i = j / fractol->zoom + fractol->y;
	fractol->z_r = 0;
	fractol->z_i = 0;
	fractol->it = 0;
	while (fractol->z_r * fractol->z_r + fractol->z_i *
			fractol->z_i < 4 && fractol->it < fractol->it_max)
	{
		fractol->perv = fractol->z_r;
		fractol->z_r = fractol->z_r * fractol->z_r -
			fractol->z_i * fractol->z_i + fractol->c_r;
		fractol->z_i = 2 * fractol->z_i * fractol->perv + fractol->c_i;
		fractol->it++;
	}
	if (fractol->it == fractol->it_max)
		put_pixel(fractol, i, j, 0x000000);
	else
		put_pixel(fractol, i, j, (fractol->color * fractol->it));
}

void    madelbrot(t_fractol *fractol)
{
    int i;
    int j;

    i = 0;
    while (i < 1000)
    {
        j = 0;
        while (j < 1000)
        {
            madelbrot_cl(fractol, i, j);
            j++;
        }
        i++;
    }
}


void        init(t_fractol *fractol, char *av)
{
    fractol->ptr = mlx_init();
    fractol->win = mlx_new_window(fractol->ptr, 1000, 1000, av);
    fractol->image = mlx_new_image(fractol->ptr, 1000, 1000);
    fractol->data = (int *)mlx_get_data_addr(fractol->image , &(fractol->bits_per_pixel), &(fractol->size_line), &(fractol->endian));
    fractol->x = -2;
    fractol->y = -2;
    fractol->zoom = 250;
    fractol->it_max = 30;
    fractol->color = 0xffabe3;
    // fractol->zoom = 250;
            // ft_putchar('$');
    madelbrot(fractol);
    mlx_put_image_to_window(fractol->ptr, fractol->win, fractol->image, 0, 0);
}

int main(int ac, char **av)
{
    t_fractol fractol;

    if (ac == 2)
    {
        if ((fractol.is_fract = is_fract(av[1])))
        {
            init(&fractol, av[1]);

            mlx_loop(fractol.ptr);
            return(0);
        }
        else
            ft_usage();
    }
    else
    {
        ft_usage();
        return (0);
    }
}

