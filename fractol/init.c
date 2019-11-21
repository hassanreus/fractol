/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseffian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 21:35:20 by hseffian          #+#    #+#             */
/*   Updated: 2019/11/20 21:35:25 by hseffian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_color(int all)
{
	if (all == 1)
		return (0xee00ff00);
	else if (all == 2)
		return (0xeeff0000);
	else if (all == 3)
		return (0xee0000ff);
	else if (all == 4)
		return (0xeeff1234);
	else if (all == 5)
		return (0xbcabcdef);
	else if (all == 6)
        return (0xaaaabbbb);
	return (0x01234567);
}

void init_mandelbord(t_fractol *fractol)
{
    fractol->x = -1.7;
    fractol->y = -1.3;
    fractol->zoom = 250;
    fractol->it_max = 30;
}

void init_julia(t_fractol *fractol)
{
    fractol->x = -1.25;
    fractol->y = -1.25;
    fractol->zoom = 250;
    fractol->it_max = 30;
    fractol->c_r = -0.80;
	fractol->c_i = 0.15;
    fractol->mouse = 1;
}

void        control_v1(t_fractol *fractol)
{
    if (fractol->is_fract == 1)
    {
        fractol->type_fract = &madelbrot_cl;
        init_mandelbord(fractol);
    }
    else
    {
        if (fractol->is_fract == 2)
        {
            fractol->type_fract = &julia_cl;
            init_julia(fractol);
        }
        else
        {
            if (fractol->is_fract == 3)
            {
                fractol->type_fract = &br;
                init_mandelbord(fractol);
            }
            else
            {
                if (fractol->is_fract == 4)
                {
                    fractol->type_fract = &new_o;
                    init_mandelbord(fractol);
                }
            }
            
        }
    } 
}

void        init(t_fractol *fractol, char *av)
{
    fractol->ptr = mlx_init();
    fractol->win = mlx_new_window(fractol->ptr, 600, 600, av);
    fractol->image = mlx_new_image(fractol->ptr, 600, 600);
    fractol->data = (int *)mlx_get_data_addr(fractol->image , &(fractol->bits_per_pixel), &(fractol->size_line), &(fractol->endian));
    fractol->mouse = 0;
    fractol->all = 1;
    control_v1(fractol);
    draw(fractol);
}