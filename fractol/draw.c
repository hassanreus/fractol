/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseffian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 21:38:06 by hseffian          #+#    #+#             */
/*   Updated: 2019/11/20 21:38:07 by hseffian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

void	put_pixel(t_fractol *fractol, int x, int y, int color)
{
	if (x < 600 && x >= 0 && y >= 0 && y < 600)
		fractol->data[x + y * 600] = color;
}

void    draw(t_fractol *fractol)
{
    int i;
    int j;

    i = 0;
    fractol->color = get_color(fractol->all);
    while (i < 600)
    {
        j = 0;
        while (j < 600)
        {
            fractol->type_fract(fractol, i, j);
            j++;
        }
        i++;
    }
    mlx_clear_window(fractol->ptr, fractol->win);
    mlx_put_image_to_window(fractol->ptr, fractol->win, fractol->image, 0, 0);
}