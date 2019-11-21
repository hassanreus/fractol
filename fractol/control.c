/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseffian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 21:28:07 by hseffian          #+#    #+#             */
/*   Updated: 2019/11/20 21:28:18 by hseffian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

void        ctl_key_press(int key, t_fractol *fractol)
{
    if (key == 1)
		fractol->it_max += 5;
	if (key == 2)
	{
		fractol->it_max -= 5;
		if (fractol->it_max < 4)
			fractol->it_max = 1;
	}
	if (key == 11)
		fractol->mouse = fractol->mouse == 0 ? 1 : 0;
    if (key == 49)
		fractol->all = fractol->all + 1 > 6 ? 1 : fractol->all + 1;
}

int         key_press(int key, t_fractol *fractol)
{
    if (key == 53)
        exit (0);
    if (key == 123)
        fractol->x += 0.1;
    if (key == 124)
        fractol->x -= 0.1;
    if (key == 126)
        fractol->y += 0.1;
    if (key == 125)
        fractol->y -= 0.1;
    ctl_key_press(key, fractol);
    draw(fractol);
    return (0);
}

int         mouse_press(int btn, int x, int y, t_fractol *fractol)
{
    if (btn == 4)
	{
		fractol->x += x / fractol->zoom - (x / (fractol->zoom * 1.3));
		fractol->y += y / fractol->zoom - (y / (fractol->zoom * 1.3));
		fractol->zoom *= 1.3;
		fractol->it_max++;
	}
	if (btn == 5)
	{
		fractol->x += x / fractol->zoom - (x / (fractol->zoom / 1.3));
		fractol->y += y / fractol->zoom - (y / (fractol->zoom / 1.3));
		fractol->zoom /= 1.3;
		fractol->it_max--;
		if (fractol->it_max < 4)
			fractol->it_max = 4;
	}
	draw(fractol);
    return (0);
}

void        control(t_fractol *fractol)
{
    mlx_hook(fractol->win, 4, 0, mouse_press, fractol);
    mlx_hook(fractol->win, 2, 0, key_press, fractol);
    mlx_hook(fractol->win, 6, 0, julia_new, fractol);
}
