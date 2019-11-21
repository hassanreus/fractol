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
    if (ft_strcmp(av, "br") == 0)
        return (3);
    if (ft_strcmp(av, "new") == 0)
        return (4);
    return (0);
}

int main(int ac, char **av)
{
    t_fractol fractol;

    if (ac == 2)
    {
        if ((fractol.is_fract = is_fract(av[1])))
        {
            init(&fractol, av[1]);
            control(&fractol);
            mlx_loop(fractol.ptr);
            return(0);
        }
        ft_usage();
    }
    else
        ft_usage();
    return (0);
}

