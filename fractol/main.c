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
    if (ft_strcmp(av, "Madelbrot") == 0)
        return (1);
    if (ft_strcmp(av, "Julia") == 0)
        return (2);
    return (0);
}

void    madelbrot(t_fractol *fractol)
{
    int i;
    int j;

    i = -1;
    while(++i < 1000){
        j = -1;
        while(++j < 1000){
            // madelbrot_cl();
        }
    }
}

void        init(t_fractol *fractol, char *av)
{
    fractol->ptr = mlx_init();
    fractol->win = mlx_new_window(fractol->ptr, 1000, 1000, av);
    fractol->image = mlx_new_image(fractol->ptr, 1000, 1000);
    mlx_get_data_addr(fractol->ptr , &(fractol->bits_per_pixel), &(fractol->size_line), &(fractol->endian));

    madelbrot(fractol);
    fractol->img_win = mlx_put_image_to_window(fractol->ptr, fractol->win, fractol->image, 10, 10);
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